/*Acknowledgement to Siddharth Prabhu with giving me knowledge of how to use yylineno, and for fixing my very strange identifier error
from the lex file*/
#include <stdio.h>
#include "microParser.h"

extern FILE* yyin;
int yylex(); 
int yyparse();

void yyerror(const char *s);

int main(int argc, char* argv[]){
	if(argc > 1){
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	
    if (yyparse() == 0){}
        //printf("Accepted\n");
}

void yyerror(const char *s){
  //printf("Not accepted\n");
}