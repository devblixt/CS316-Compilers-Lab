%{
/*Acknowledgements: 
    https://github.com/maheshbabugorantla/Fall_2017_Compilers
    https://github.com/tomhickey50/ECE468-1/
    Rishit Saiya : https://github.com/rishitsaiya/CS316-Compilers-Lab
    Props to Siddharth Prabhu for helping me out with specific bugs as well! 
*/
   
    #include <iostream>
    #include <string>
    #include <vector>
    #include "makers.hpp"
    #include "parser.h"

    int yylex();
    void yyerror(char const *s);
%}

DIGIT               [0-9]
IDENTIFIER          [a-zA-Z][a-zA-Z0-9]*
COMMENT             [/][/]
ASSIGN_OP           ":="
ADD_OP              "+"
SUB_OP              "-"
MUL_OP              "*"
DIV_OP              "/"
EQ_OP               "="
NEQ_OP              "!="
LT_OP               "<"
LTE_OP              "<="
GT_OP               ">"
GTE_OP              ">="
OPEN_PAR            "("
CLOSED_PAR          ")"
SEMICOLON           ";"
COMMA               ","

%%

PROGRAM							{ return _PROGRAM; }
BEGIN							{ return _BEGIN; }
END								{ return _END; }
FUNCTION						{ return _FUNCTION; }
READ							{ return _READ; }
WRITE							{ return _WRITE; }
IF								{ return _IF; }
ELSE							{ return _ELSE; }
ENDIF							{ return _ENDIF; }
WHILE							{ return _WHILE; }
ENDWHILE						{ return _ENDWHILE; }
RETURN							{ return _RETURN; }
INT								{ return _INT; }
VOID							{ return _VOID; }
STRING							{ return _STRING; }
FLOAT							{ return _FLOAT; }
BREAK                           {return BREAK;}
CONTINUE                        { return CONTINUE;}
{COMMENT}.+\n                   {}

{ASSIGN_OP}                     { return ASSIGN_OP; }
{ADD_OP}                        { return ADD_OP; }
{SUB_OP}                        { return SUB_OP; }
{MUL_OP}                        { return MUL_OP; }
{DIV_OP}                        { return DIV_OP; }
{EQ_OP}                         { return EQ_OP; }
{NEQ_OP}                        { return NEQ_OP; }
{LT_OP}                         { return LT_OP; }
{LTE_OP}                        { return LTE_OP; }
{GT_OP}                         { return GT_OP; }
{GTE_OP}                        { return GTE_OP; }
{OPEN_PAR}                      { return OPEN_PAR; }
{CLOSED_PAR}                    { return CLOSED_PAR; }
{SEMICOLON}                     { return SEMICOLON; }
{COMMA}                         { return COMMA; }


{DIGIT}+                        { yylval.intval = atoi(yytext);
                                  return INTLITERAL; }

\"[^"]*\"                       { yylval.stringval = new std::string (yytext);
                                  return STRINGLITERAL; }

{IDENTIFIER}                    { yylval.stringval = new std::string (yytext);
                                  return IDENTIFIER; }

{DIGIT}*\.{DIGIT}+              { yylval.floatval = atof(yytext);
                                  return FLOATLITERAL; }

[ \t\n]                         {}

%%

int yywrap()
{
  	return 1;
}