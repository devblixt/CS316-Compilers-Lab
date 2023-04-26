%{
	#include <stdio.h> 
	#include <string.h> 
	#include <stdlib.h> 
	#include <math.h>  
	#include <ctype.h>
	 #include <iostream>
    #include <stdio.h>
    #include <iterator>
    #include <map>
    #include <stack>
    #include <sstream>
    #include <vector>
    #include <string>
	#include "wrapper.h"
	#include "makers.h"

	int yylex();
	extern int yylineno; //For extracting line numbers
	
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
	int while_label_counter = 1;
	bool is_if = false;
	bool is_while = false;

    std::stringstream ss;

    std::vector <std::string> ID_Vector, vars, strConst;

    int registerCounter = 1;
    std::stack <std::string> defined_labels;
	std::stack <std::string> defined_while_labels;

    std::vector <ThreeAC> IR;

	int zoneCheck = 0;
	struct StrEntry{
		char* ID;
		char* Val;
		int line_num;
	};

	struct VarEntry{
		char* ID;
		char* Type;
		int line_num;
	};

	struct STable{
		char first;
		int num_variables;
		int num_strings;
		struct VarEntry var_s[80];
		struct StrEntry str_s[80];
	};
	struct CodeObject{
		char* instruction;
		char* codelist[1000];
		int num;
		char* result;
		char* type;
		char* factor;
		struct CodeObject* next;
	};

	struct STable SYMBOL_TABLE[80];

	void yyerror(const char *err);


%}
%locations
%token LEX_PROGRAM 
%token _BEGIN 
%token LEX_CONTINUE //
%token VOID // 
%token INT //
%token FLOAT //
%token STRING //
%token READ //
%token WRITE //
%token FUNCTION //
%token RETURN //
%token IF //
%token ELSE //
%token ENDIF //
%token WHILE //
%token ENDWHILE //
%token BREAK //
%token END 

%token ADD_OP//
%token SUB_OP
%token MUL_OP
%token DIV_OP
%token BRACKETS_OP
%token BRACKETC_OP
%token GEQ_OP
%token LEQ_OP
%token GT_OP
%token LT_OP
%token COMMA_OP
%token SC_OP
%token ASSIGN_OP 
%token EQ_OP
%token NEQ_OP

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
%type <ASTPtr> assign_expr factor factor_prefix expr_prefix expr


%%
// LEX_Program
LEX_program:	LEX_PROGRAM id _BEGIN
			{
				scope.push("GLOBAL");
				zoneCheck++;
			}

 			pgm_body END
			{
				scope.pop();
								zoneCheck++;

			};

id:		IDENTIFIER {
					$$ = $1;
				// if(variable_declaration==1 && scope == 0){
				// 	current->codelist[current->num] = malloc(400*sizeof(char));
				// 	strcat(current->codelist[current->num], "var "); 
				// 	strcat(current->codelist[current->num], $$); 
				// 	current->num++;
				// }
				// else if(readwrite == 1){
				// 	current->codelist[current->num] = malloc(400*sizeof(char));
				// 	strcat(current->codelist[current->num], current->instruction); 
				// 	int i;
				// 	for(i = 0; i < SYMBOL_TABLE[SCOPE].num_strings; i++ ){
				// 		if(!strcmp(SYMBOL_TABLE[SCOPE].str_s[i].ID,$$)){
				// 			strcat(current->codelist[current->num], "S ");
				// 			break;
				// 		}
				// 	}
				// 	if(i == SYMBOL_TABLE[SCOPE].num_strs){
				// 		for(i = 0; i < SYMBOL_TABLE[SCOPE].num_strings; i++ ){
				// 			if(!strcmp(SYMBOL_TABLE[0].str_s[i].ID,$$)){
				// 				strcat(current->codelist[current->num], "S ");
				// 				break;
				// 			}
				// 		}
				// 	}
				// 	for(i = 0; i < SYMBOL_TABLE[SCOPE].num_variables; i++ ){
				// 		if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].ID,$$)){
				// 			if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].Type,"INT")){
				// 				strcat(current->codelist[current->num], "I ");
				// 			}
				// 			else{
				// 				strcat(current->codelist[current->num], "R ");
				// 			}
				// 			break;
				// 		}
				// 	}
				// 	if(i == SYMBOL_TABLE[SCOPE].num_vars){
				// 		for(i = 0; i < SYMBOL_TABLE[0].num_variables; i++ ){
				// 			if(!strcmp(SYMBOL_TABLE[0].var_s[i].ID,$$)){
				// 				if(!strcmp(SYMBOL_TABLE[0].var_s[i].Type,"INT")){
				// 					strcat(current->codelist[current->num], "I ");
				// 				}
				// 				else{
				// 					strcat(current->codelist[current->num], "R ");
				// 				}
				// 				break;
				// 			}
				// 		}
				// 	}
				// 	strcat(current->codelist[current->num], $$); 
				// 	current->num++;
				// }
			};
pgm_body:	decl func_declarations;
decl:		string_decl decl | var_decl decl | %empty {
		    	addSymbolTable();
								zoneCheck++;
		    };

//Global String declaration
string_decl:	STRING id ASSIGN_OP str SC_OP
									{
														zoneCheck++;
										w.value[0] = "STRING";
										w.value[1] = $4;
										r = table.insert(std::pair<std::string, wrapper> ($2, w));
										if(!r.second){
											yyerror($2);
										}
										ss.str("");
										ss << "str " << $2 << " " << $4;
										strConst.push_back(ss.str());
										
										// if(SYMBOL_TABLE[SCOPE].first == 'c')
										// {
										// 	SYMBOL_TABLE[SCOPE].first = 's';
										// }
											
										// for(int i = 0; i <= SYMBOL_TABLE[SCOPE].num_strings - 1; i++ ){
										// 	if(!strcmp(SYMBOL_TABLE[SCOPE].str_s[i].ID,$2))
										// 	{
										// 		printf("DECLARATION ERROR %s",$2);
										// 		// printf("(previous declaration was at line %d)", SYMBOL_TABLE[SCOPE].str_s[i].line_num);
										// 		nwl();
										// 		return 0;
										// 	}
										// }
										// for(int i = 0; i <= SYMBOL_TABLE[SCOPE].num_variables - 1; i++ ){
										// 	if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].ID,$2)){
										// 		printf("DECLARATION ERROR %s", $2);
										// 		nwl();
										// 		return 0;
										// 	}
										// }
										// $$ = malloc(sizeof(struct StrEntry())); 
										// $$->ID = $2; 
										// $$->line_num = yylineno; 
										// $$->Val = $4; 
										// SYMBOL_TABLE[SCOPE].str_s[SYMBOL_TABLE[SCOPE].num_strings] = *($<s_entry>$); 
										// SYMBOL_TABLE[SCOPE].num_strings = Increment(SYMBOL_TABLE[SCOPE].num_strings);
										// printf("str %s %s\n",$2,$4);//
									}
									; 
str:		STRINGLITERAL {$$ = $1;};

//Variable declaration
var_decl:	var_type id_list SC_OP
					{
										zoneCheck++;
						for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
							w.value[0] = $1;
							w.value[1] = "";
							r = table.insert(std::pair<std::string, wrapper> (*itr, w));
							if(!r.second){
								std::string temp = *itr;
								yyerror(temp.c_str());
							}
							vars.push_back(*itr);
						}
						ID_Vector.clear();
		    		}
		    ;
var_type:	FLOAT { 				zoneCheck++; } | INT {				zoneCheck++; }; // removed tags
any_type:	var_type | VOID;

id_list:	id id_tail {
						ID_Vector.push_back($1);
								zoneCheck++;
				};

id_tail:	COMMA_OP id id_tail {ID_Vector.push_back($2);} | %empty ;



//Function parameter list
param_decl_list:	param_decl param_decl_tail | %empty;

param_decl:	var_type id {
					zoneCheck++;
						w.value[0] = $1;
						w.value[1] = "";
						r = table.insert(std::pair<std::string, wrapper>($2, w));
						if(!r.second){
							yyerror($2);
						}
			};
param_decl_tail:	COMMA_OP param_decl param_decl_tail | %empty;



//Function declarations
func_declarations:	func_decl func_declarations | %empty;
func_decl:	FUNCTION any_type id 
								{
									zoneCheck++;
									scope.push($3);
									ss.str("");
									ss << $3;
									IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
								}
								BRACKETS_OP param_decl_list BRACKETC_OP _BEGIN func_body END{
									scope.pop();
								};
func_body:	decl stmt_list ;



//Statement list
stmt_list:	stmt stmt_list | %empty;
stmt:		base_stmt | if_stmt | while_stmt;
base_stmt:	assign_stmt | read_stmt | write_stmt | return_stmt;


//Basic Statements list
assign_stmt:	assign_expr SC_OP {

					zoneCheck++;
		    	makeIR($1);
		    	removeAST($1);
		    };

assign_expr:	id ASSIGN_OP expr {

					zoneCheck++;
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = $1;
		    	ASTNodeVar * node = new ASTNodeVar(key, mapp[key].value[0]);
		    	$$ = new ASTNodeOp("=", node, $3);
		    }; // String changed

read_stmt:	READ BRACKETS_OP id_list BRACKETC_OP SC_OP {
					zoneCheck++;
				for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
					std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
					if (mapp[*itr].value[0] == "INT")
						IR.push_back(ThreeAC("READI", "", "", *itr));
					else
						IR.push_back(ThreeAC("READF", "", "", *itr));
					}
					ID_Vector.clear();
		    };

write_stmt:	WRITE BRACKETS_OP id_list BRACKETC_OP SC_OP {
					zoneCheck++;
		    	for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("WRITEI", "", "", *itr));
				else if (mapp[*itr].value[0] == "FLOAT")
					IR.push_back(ThreeAC("WRITEF", "", "", *itr));
				else
					IR.push_back(ThreeAC("WRITES", "", "", *itr));
			}
			ID_Vector.clear();
		    }
		;
return_stmt:	RETURN expr SC_OP;



//Expressions
expr:		expr_prefix factor {
					zoneCheck++;
		    	if($1 != NULL){
		    		$1->right = $2;
		    		$$ = $1;
		    	}
		    	else{
		    		$$ = $2;
		    	}
		    };

expr_prefix:	expr_prefix factor addop {
					zoneCheck++;
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
		    };

factor:		factor_prefix postfix_expr {
					zoneCheck++;
		    	if($1 != NULL){
		    		$1->right = $2;
		    		$$ = $1;
		    	}
		    	else{
		    		$$ = $2;
		    	}
		    };

factor_prefix:	factor_prefix postfix_expr mulop {
					zoneCheck++;
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
		    };

postfix_expr:	primary {$$ = $1;} | call_expr {$$ = $1;
				zoneCheck++;};
call_expr:	id BRACKETS_OP expr_list BRACKETC_OP {$$ = $3;
				zoneCheck++;};
expr_list:	expr expr_list_tail {$$ = $1;} | %empty {$$ = NULL;
				zoneCheck++;};

expr_list_tail:	COMMA_OP expr expr_list_tail {$$ = $2;} | %empty {$$ = NULL;} ;

primary:	BRACKETS_OP expr BRACKETC_OP {$$ = $2;} | 
			id {
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = $1;
		    	$$ = new ASTNodeVar(key, mapp[key].value[0]);
			}| INTLITERAL {$$ = new ASTNodeInt($1);}| FLOATLITERAL {$$ = new ASTNodeFloat($1);};

addop:		ADD_OP {$$ = new ASTNodeOp("+");} | SUB_OP {$$ = new ASTNodeOp("-");} ;
mulop:		MUL_OP { $$ = new ASTNodeOp("*");} | DIV_OP { $$ = new ASTNodeOp("/");};


//Complex statements and conditions	
if_stmt:	IF 
				{
									zoneCheck++;
					is_if = true;
					pushBlock();
				}
				BRACKETS_OP cond BRACKETC_OP decl stmt_list {
					ss.str("");
					ss << "label" << labelCounter++;
					IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
					defined_labels.pop();
					defined_labels.push(ss.str());
				}
				else_part {
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
		    		defined_labels.pop();
				} ENDIF {
					scope.pop();
				};

else_part:	ELSE 
				{
					pushBlock();
									zoneCheck++;
				}
				decl stmt_list {scope.pop();} | %empty ;

cond:		expr compop expr {
					zoneCheck++;
								std::string t;
									std::string op1 = CondExprIR($1, &t);
									IR.push_back(ThreeAC("", "", "", "", "SAVE"));
									std::string op2 = CondExprIR($3, &t);
									ss.str("");
									if(is_if)
									{
										ss << "label" << labelCounter++;
										IR.push_back(ThreeAC($2, op1, op2, ss.str(), t)); 
										defined_labels.push(ss.str());
										is_if = false; 
									}
									 
									if(is_while)
									{
										ss << "labelw" << while_label_counter++;
										IR.push_back(ThreeAC($2, op1, op2, ss.str(), t)); 
										defined_while_labels.push(ss.str());
										is_while = false; 
									}
				zoneCheck++;
									removeAST($1); 
									removeAST($3);
							};

compop:		LT_OP {$$ = (char *) "GE";} |
			GT_OP {$$ = (char *) "LE"; }|
			EQ_OP{$$ = (char *) "NE"; }|
			NEQ_OP{$$ = (char *) "EQ"; }|
			LEQ_OP{$$ = (char *) "GT"; }|
			GEQ_OP {$$ = (char *) "LT"; };

// init_stmt
// 		    : assign_expr { $$ = $1; }
// 		    | %empty 	   { $$ = NULL; }
// 		    ;

// incr_stmt
// 		    : assign_expr { $$ = $1; }
// 		    | %empty 	   { $$ = NULL; }
// 		    ;


while_stmt:	WHILE 
					{
						is_while = true;
								zoneCheck++;
						pushBlock();
						ss.str("");
						ss << "labelw" << while_label_counter++;
						defined_while_labels.push(ss.str());
						IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
						// SCOPE = SCOPE + 1; 
						// tbl_name[SCOPE] = "BLOCK ";
						// SYMBOL_TABLE[SCOPE].first = 'c'; 
						// SYMBOL_TABLE[SCOPE].num_strings = 0; 
						// SYMBOL_TABLE[SCOPE].num_variables = 0; 
	
					}
					BRACKETS_OP cond BRACKETC_OP decl aug_stmt_list
					{
						// makeIR($5);
		    			// removeAST($5);
						zoneCheck++;
						std::string temp = defined_while_labels.top();
						defined_while_labels.pop();
						IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
						defined_while_labels.push(temp);
						IR.push_back(ThreeAC("LABEL", "", "", temp));
					} ENDWHILE {
							// IR.push_back(ThreeAC("LABEL", "", "", defined_while_labels.top()));
							// defined_while_labels.pop();
							scope.pop();

				zoneCheck++;
						};

aug_stmt_list:	aug_stmt aug_stmt_list | %empty;
aug_stmt:	base_stmt | aug_if_stmt | while_stmt | LEX_CONTINUE{
	std::string temp = defined_while_labels.top();
	defined_while_labels.pop();
	IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
	defined_while_labels.push(temp);
} SC_OP | BREAK{
	IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
} SC_OP;

aug_if_stmt:	IF {
					is_if = true;
					pushBlock();
					}
				BRACKETS_OP cond BRACKETC_OP decl aug_stmt_list 
				{
						zoneCheck++;
					ss.str("");
					ss << "label" << labelCounter++;
					IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
					defined_labels.pop();
					defined_labels.push(ss.str());
				}
				aug_else_part 
				{
						zoneCheck++;
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
		    		defined_labels.pop();
				}
				ENDIF {

						zoneCheck++;
					scope.pop();
				};
aug_else_part:	ELSE 
				{

					zoneCheck++;
					pushBlock();
				} decl aug_stmt_list {scope.pop();} | %empty;

%%