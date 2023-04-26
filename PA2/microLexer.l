%{
	#include "microParser.h"
%}


DIGIT [0-9]
IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*
STRINGLITERAL \"(\\.|[^"\\])*\"
COMMENT "//".*
OPERATOR [:]|[+]|[-]|[*]|[/]|[=]|[!]|[<]|[>]|[(]|[)]|[,]|[;] 
SPACE [\r\n\t ]
%%

{COMMENT} {}

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
	return INT;
}

VOID  {
	return VOID;
}

STRING  {
	return STRING;
}

FLOAT  {
	return FLOAT;
}
CONTINUE  {
	return CONTINUE;
}

BREAK {
	return BREAK;
}


{STRINGLITERAL} {
	return STRINGLITERAL;
}

{IDENTIFIER} {
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
