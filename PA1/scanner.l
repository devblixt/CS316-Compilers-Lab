%{
%}
INTLITERAL [0-9]*
FLOATLITERAL [0-9]*\.[0-9]+
IDENTIFIER [_|a-z|A-Z][_|a-z|A-Z|0-9]*
COMMENT [/]
KEYWORD "PROGRAM"|"BEGIN"|"END"|"FUNCTION"|"READ"|"WRITE"|"IF"|"ELSE"|"ENDIF"|"WHILE"|"ENDWHILE"|"BREAK"|"CONTINUE"|"RETURN"|"INT"|"VOID"|"STRING"|"FLOAT"
OPERATOR ":="|"+"|"-"|"*"|"/"|"="|"!="|"<"|">"|"("|")"|";"|","|"<="|">="
WHITESPACE [ \r\t\n]

%%

{INTLITERAL} {
	fprintf(yyout, "Token Type: INTLITERAL\nValue: %s\n",yytext);
}
{FLOATLITERAL} {
	fprintf(yyout, "Token Type: FLOATLITERAL\nValue: %s\n",yytext);
}
{KEYWORD} {
    fprintf(yyout, "Token Type: KEYWORD\nValue: %s\n",yytext);
}
{IDENTIFIER} {
	fprintf(yyout, "Token Type: IDENTIFIER\nValue: %s\n",yytext);
}
{COMMENT}{COMMENT}.+\n {}
{OPERATOR} {
	fprintf(yyout, "Token Type: OPERATOR\nValue: %s\n",yytext);
}
{WHITESPACE}+ {}
\"(\\.|[^"\\])*\" {
	fprintf(yyout, "Token Type: STRINGLITERAL\nValue: %s\n",yytext);
}

%%

int yywrap(){
  	return 1;
}

int main(int argc, char* argv[]){
	if(argc > 1){
		FILE *takeFrom = fopen(argv[1], "r");
        FILE *giveOut = fopen(argv[2], "w");
		if(takeFrom){
            yyin = takeFrom;
        }
        if(giveOut){
            yyout = giveOut;
        }
	}
    yylex();
    return 0;
}