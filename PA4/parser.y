%{
    #include <iostream>
    #include <stdio.h>
    #include <iterator>
    #include <map>
    #include <stack>
    #include <sstream>
    #include <vector>
    #include <string>

    #include "headers/astNode.h"
    #include "headers/threeAC.h"
    #include "main.h"

    int yylex();
    void yyerror(char const* msg);

    extern void addSymbolTable();
    extern void makeIR(ASTNode * ast);
    extern void removeAST(ASTNode * ast);
    extern void pushBlock();
    extern std::string CondExprIR(ASTNode * node, std::string * t);

    wrapper w, p;    
    std::stack <std::string> scope;
    std::pair <std::map <std::string, wrapper>::iterator, bool> r;
    std::map <std::string, wrapper> table;
    std::map <std::string, std::map<std::string, wrapper> > symbolTable;

    int blockCounter = 0;
    int labelCounter = 1;

    std::stringstream ss;

    std::vector <std::string> idVec, vars, strConst;

    int registerCounter = 1;
    std::stack <std::string> labels;

    std::vector <ThreeAC> IR;
%}

%token KW_PROGRAM
%token KW_BEGIN
%token KW_END
%token KW_FUNCTION
%token KW_READ
%token KW_WRITE
%token KW_IF
%token KW_ELSE
%token KW_FI
%token KW_FOR
%token KW_ROF
%token KW_BREAK
%token KW_CONTINUE
%token KW_RETURN
%token <sval> KW_INT
%token KW_VOID
%token KW_STRING
%token <sval> KW_FLOAT

%token OP_ASSIGN	/* := */
%token OP_ADD		/* +  */
%token OP_SUB		/* -  */
%token OP_MUL		/* *  */
%token OP_DIV		/* /  */ 
%token OP_EQ		/* =  */
%token OP_NEQ		/* != */
%token OP_LT		/* <  */
%token OP_GT		/* >  */
%token OP_OP		/* (  */
%token OP_CP		/* )  */
%token OP_SEMICOLON	/* ;  */
%token OP_COMMA		/* ,  */
%token OP_LEQ		/* <= */
%token OP_GEQ		/* >= */

%token <sval> IDENTIFIER
%token <sval> INTLITERAL
%token <sval> FLOATLITERAL
%token <sval> STRINGLITERAL

%union {
    int ival;
    float fval;
    char * sval;
    ASTNode * ASTPtr;
}

%type <sval> id str var_type compop 
%type <ASTPtr> primary postfix_expr call_expr expr_list expr_list_tail addop mulop
%type <ASTPtr> init_stmt incr_stmt assign_expr factor factor_prefix expr_prefix expr

%%

/* Program */
program     
		    : KW_PROGRAM id KW_BEGIN {
			scope.push("GLOBAL");
		    }
		    pgm_body KW_END {
			scope.pop();
		    }
		    ;

id          
		    : IDENTIFIER {
		    	$$ = $1;
		    }
		    ;

pgm_body    
		    : decl func_declarations 
		    ;

decl        
		    : string_decl decl 
		    | var_decl decl 
		    | %empty {
		    	addSymbolTable();
		    }
		    ;

/* Global String Declaration */
string_decl
		    : KW_STRING id OP_ASSIGN str OP_SEMICOLON {
			w.value[0] = "STRING";
			w.value[1] = $4;
			r = table.insert(std::pair<std::string, wrapper> ($2, w));
			if(!r.second){
				yyerror($2);
			}
			ss.str("");
			ss << "str " << $2 << " " << $4;
			strConst.push_back(ss.str());
		    }
		    ;

str
		    : STRINGLITERAL {
		    	$$ = $1;
		    }
		    ;

/* Variable Declaration */
var_decl
		    : var_type id_list OP_SEMICOLON {
			for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				w.value[0] = $1;
				w.value[1] = "";
				r = table.insert(std::pair<std::string, wrapper> (*itr, w));
				if(!r.second){
					std::string temp = *itr;
					yyerror(temp.c_str());
				}
				vars.push_back(*itr);
			}
			idVec.clear();
		    }
		    ;

var_type
		    : KW_FLOAT { $$ = $1; }
		    | KW_INT { $$ = $1; }
		    ;

any_type
		    : var_type 
		    | KW_VOID 
		    ;

id_list
		    : id id_tail {
			idVec.push_back($1);
		    }
		    ;

id_tail
		    : OP_COMMA id id_tail {
			idVec.push_back($2);
		    }
		    | %empty 
		    ;

/* Function Parameter List */
param_decl_list
		    : param_decl param_decl_tail 
		    | %empty 
		    ; 

param_decl
		    : var_type id {
			w.value[0] = $1;
			w.value[1] = "";
			r = table.insert(std::pair<std::string, wrapper>($2, w));
			if(!r.second){
				yyerror($2);
			}
		    }
		    ;

param_decl_tail
		    : OP_COMMA param_decl param_decl_tail 
		    | %empty 
		    ;

/* Function Declarations */
func_declarations
		    : func_decl func_declarations 
		    | %empty 
		    ;

func_decl
		    : KW_FUNCTION any_type id {
			scope.push($3);
		    }
		    OP_OP param_decl_list OP_CP KW_BEGIN func_body KW_END {
			scope.pop();
		    } 
		    ;

func_body
		    : decl stmt_list 
		    ;

/* Statement List */ 
stmt_list
		    : stmt stmt_list 
		    | %empty 
		    ;

stmt
		    : base_stmt 
		    | if_stmt 
		    | for_stmt 
		    ;

base_stmt
		    : assign_stmt 
		    | read_stmt 
		    | write_stmt 
		    | return_stmt 
		    ;

/* Basic Statements */
assign_stmt
		    : assign_expr OP_SEMICOLON {
		    	makeIR($1);
		    	removeAST($1);
		    }
		    ;

assign_expr
		    : id OP_ASSIGN expr {
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = $1;
		    	ASTNodeVar * node = new ASTNodeVar(key, mapp[key].value[0]);
		    	$$ = new ASTNodeOp("=", node, $3);
		    }
		    ;

read_stmt
		    : KW_READ OP_OP id_list OP_CP OP_SEMICOLON {
			for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("READI", "", "", *itr));
				else
					IR.push_back(ThreeAC("READF", "", "", *itr));
			}
			idVec.clear();
		    }
		    ;

write_stmt
		    : KW_WRITE OP_OP id_list OP_CP OP_SEMICOLON {
		    	for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("WRITEI", "", "", *itr));
				else if (mapp[*itr].value[0] == "FLOAT")
					IR.push_back(ThreeAC("WRITEF", "", "", *itr));
				else
					IR.push_back(ThreeAC("WRITES", "", "", *itr));

			}
			idVec.clear();
		    }
		    ;

return_stmt
		    : KW_RETURN expr OP_SEMICOLON
		    ;

/* Expressions */
expr
		    : expr_prefix factor {
		    	if($1 != NULL){
		    		$1->right = $2;
		    		$$ = $1;
		    	}
		    	else{
		    		$$ = $2;
		    	}
		    }
		    ;

expr_prefix
		    : expr_prefix factor addop {
		    	if($1 != NULL){
		    		$3->left = $1;
		    		$1->right = $2;
		    	}
		    	else{
		    		$3->left = $2;
		    	}
		    	$$ = $3;
		    }
		    | %empty {
		    	$$ = NULL;
		    }
		    ;

factor
		    : factor_prefix postfix_expr {
		    	if($1 != NULL){
		    		$1->right = $2;
		    		$$ = $1;
		    	}
		    	else{
		    		$$ = $2;
		    	}
		    }
		    ;

factor_prefix
		    : factor_prefix postfix_expr mulop {
		    	if($1 != NULL){
		    		$3->left = $1;
		    		$2->right = $2;
		    	}
		    	else{
		    		$3->left = $2;
		    	}
		    	$$ = $3;
		    }
		    | %empty {
		    	$$ = NULL;
		    }
		    ;

postfix_expr
		    : primary { $$ = $1; }
		    | call_expr { $$ = $1; }
		    ;

call_expr
		    : id OP_OP expr_list OP_CP {
		    	$$ = $3;
		    }
		    ;

expr_list
		    : expr expr_list_tail {
		    	$$ = $1;
		    }
		    | %empty {
		    	$$ = NULL;
		    }
		    ;

expr_list_tail
		    : OP_COMMA expr expr_list_tail {
		    	$$ = $2;
		    }
		    | %empty {
		    	$$ = NULL;
		    }
		    ;

primary
		    : OP_OP expr OP_CP { $$ = $2; }
		    | id { 
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = $1;
		    	$$ = new ASTNodeVar(key, mapp[key].value[0]);
		    }
		    | INTLITERAL { $$ = new ASTNodeInt($1); }
		    | FLOATLITERAL { $$ = new ASTNodeFloat($1); }
		    ;

addop
		    : OP_ADD { $$ = new ASTNodeOp("+"); }
		    | OP_SUB { $$ = new ASTNodeOp("-"); }
		    ;

mulop
		    : OP_MUL { $$ = new ASTNodeOp("*"); }
		    | OP_DIV { $$ = new ASTNodeOp("/"); }
		    ;


/* Complex Statements and Condition */
if_stmt
		    : KW_IF {
			pushBlock();
		    }
		    OP_OP cond OP_CP decl stmt_list {
			ss.str("");
			ss << "label" << labelCounter++;
			IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
			IR.push_back(ThreeAC("LABEL", "", "", labels.top()));
			labels.pop();
			labels.push(ss.str());
		    }
		    else_part {
		    	IR.push_back(ThreeAC("LABEL", "", "", labels.top()));
		    	labels.pop();
		    }
		    KW_FI {
		    	scope.pop();
		    }
		    ;

else_part
		    : KW_ELSE {
			pushBlock();
		    }
		    decl stmt_list {
			scope.pop();
		    }
		    | %empty 
		    ;

cond
		    : expr compop expr {
		    	std::string t;
		    	std::string op1 = CondExprIR($1, &t);
		    	IR.push_back(ThreeAC("", "", "", "", "SAVE"));
		    	std::string op2 = CondExprIR($3, &t);
		    	ss.str("");
		    	ss << "label" << labelCounter++;  
		    	IR.push_back(ThreeAC($2, op1, op2, ss.str(), t)); 
		    	labels.push(ss.str()); 
		    	removeAST($1); 
		    	removeAST($3);
		    }
		    ;

compop
		    : OP_LT { $$ = (char *) "GE"; }
		    | OP_GT { $$ = (char *) "LE"; }
		    | OP_EQ { $$ = (char *) "NE"; }
		    | OP_NEQ { $$ = (char *) "EQ"; }
		    | OP_LEQ { $$ = (char *) "GT"; }
		    | OP_GEQ { $$ = (char *) "LT"; }
		    ;

init_stmt
		    : assign_expr { $$ = $1; }
		    | %empty 	   { $$ = NULL; }
		    ;

incr_stmt
		    : assign_expr { $$ = $1; }
		    | %empty 	   { $$ = NULL; }
		    ;

for_stmt
		    : KW_FOR {
			pushBlock();
		    }
		    OP_OP init_stmt OP_SEMICOLON {
		    	makeIR($4);
		    	removeAST($4);
		    	ss.str("");
		    	ss << "label" << labelCounter++;
		    	labels.push(ss.str());
		    	IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
		    }
		    cond OP_SEMICOLON incr_stmt OP_CP decl aug_stmt_list {
		    	makeIR($9);
		    	removeAST($9);
		    	std::string temp = labels.top();
		    	labels.pop();
		    	IR.push_back(ThreeAC("JUMP", "", "", labels.top()));
		    	labels.push(temp);
		    	IR.push_back(ThreeAC("LABEL", "", "", temp));
		    }
		    KW_ROF {
			scope.pop();
		    }
		    ;

aug_stmt_list
		    : aug_stmt aug_stmt_list 
		    | %empty 
		    ;

aug_stmt
		    : base_stmt 
		    | aug_if_stmt 
		    | for_stmt 
		    | KW_CONTINUE OP_SEMICOLON 
		    | KW_BREAK OP_SEMICOLON 
		    ;

aug_if_stmt
		    : KW_IF OP_OP cond OP_CP decl aug_stmt_list aug_else_part KW_FI 
		    ;

aug_else_part
		    : KW_ELSE decl aug_stmt_list 
		    | %empty 
		    ;

%%
