%{
	#include "microParser.h"

%}

%option yylineno

DIGIT [0-9]
IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*
STRINGLITERAL ["][^"]*["]
COMMENT "//".*
OPERATOR [:]|[+]|[-]|[*]|[/]|[=]|[!]|[<]|[>]|[(]|[)]|[,]|[;] 
SPACE [\r\t ]
NEWLINE [\n]
%%

{COMMENT} {}
{NEWLINE} {}
{SPACE}+ {}

{DIGIT}+ {
	return INTLITERAL;
}

{DIGIT}+"."{DIGIT}* {
	return FLOATLITERAL;
}

BEGIN  {
	return _BEGIN;
}

PROGRAM  {
	return PROGRAM;
}

END  {
	return END;
}

FUNCTION  {
	return FUNCTION;
}

READ  {
	return READ;
}

WRITE  {
	return WRITE;
}

IF  {
	return IF;
}

ELSE  {
	return ELSE;
}

ENDIF  {
	return ENDIF;
}

WHILE  {
	return WHILE;
}

ENDWHILE  {
	return ENDWHILE;
}

RETURN  {
	return RETURN;
}

INT  {
		yylval.type = strdup(yytext);

	return INT;
}

VOID  {
	
	return VOID;
}

STRING  {
		yylval.type = strdup(yytext);

	return STRING;
}

FLOAT  {
	yylval.type = strdup(yytext);
	return FLOAT;
}
CONTINUE  {
	return CONTINUE;
}

BREAK {
	return BREAK;
}


{STRINGLITERAL} {
	yylval.s = strdup(yytext);
	return STRINGLITERAL;
}

{IDENTIFIER} {
	yylval.s = strdup(yytext);
	return IDENTIFIER;
}

{OPERATOR} {
	return *yytext;
}

%%

int yywrap()
{
  	return 1;
}
