%{
#include <iostream>
#include <string>
#include "makers.h"
#include "microParser.h"
using namespace std;
%}

%option yylineno
KEYWORD BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|ENDIF|STRING|FLOAT|RETURN|WHILE|ENDWHILE|BREAK|INT|VOID|CONTINUE|PROGRAM
OPERATOR ":="|"<="|">="|"!="|"("|")"|"+"|"-"|"*"|"/"|"="|"<"|">"|";"|","
WHITESPACE [ \r\n\t]
COMMENT [/]
INTLITERAL [0-9]*
FLOATLITERAL [0-9]*\.[0-9]+
IDENTIFIER [_|a-z|A-Z][_|a-z|A-Z|0-9]*


%%

{COMMENT}{COMMENT}.+\n {}

{WHITESPACE}+ {}

{INTLITERAL} {
	//fprintf(yyout, "Token Type: INTLITERAL\nValue: %s\n",yytext);
	yylval.sval = strdup(yytext); return INTLITERAL;
}

{FLOATLITERAL} {
	//fprintf(yyout, "Token Type: FLOATLITERAL\nValue: %s\n",yytext);
	yylval.sval = strdup(yytext); return FLOATLITERAL;
}
\"(\\.|[^"\\])*\" { // String literal
	//fprintf(yyout, "Token Type: STRINGLITERAL\nValue: %s\n",yytext);
	yylval.sval = strdup(yytext);
	return STRINGLITERAL;
}

BEGIN {
	return _BEGIN;
}
END {
	return END;
}
FUNCTION {
	return FUNCTION;
}
READ {
	return READ;
}
WRITE {
	return WRITE;
}
IF {
	return IF;
}
ELSE {
	return ELSE;
}
ENDIF {
	return ENDIF;
}
STRING {
	return STRING;
}
FLOAT {
	yylval.sval = strdup(yytext);
	return FLOAT;
}
RETURN {
	return RETURN;
}
WHILE {
	return WHILE;
}
ENDWHILE {
	return ENDWHILE;
}
BREAK {
	return BREAK;
}
INT {
	yylval.sval = strdup(yytext);
	return INT;
}
VOID {
	return VOID;
}
CONTINUE {
	return LEX_CONTINUE;
}
PROGRAM {
	return LEX_PROGRAM;
}
"+" { 	return ADD_OP;}
"-" {	return SUB_OP;}
"*" {	return MUL_OP;}
"/" {	return DIV_OP;}
":=" {	return ASSIGN_OP;}
"=" {	return EQ_OP;}
"!=" {	return NEQ_OP;}
">" {	return GT_OP;}
"<" {	return LT_OP;}
">=" {	return GEQ_OP;}
"<=" {	return LEQ_OP;}
";" {	return SC_OP;}
"," {	return COMMA_OP;}
"(" {	return BRACKETS_OP;}
")" {	return BRACKETC_OP;}

{IDENTIFIER} {
	//fprintf(yyout, "Token Type: IDENTIFIER\nValue: %s\n",yytext);
	yylval.sval = strdup(yytext);
	return IDENTIFIER;
}

%%

int yywrap()
{
  	return 1;
}