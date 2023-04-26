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
#include <stdio.h>


extern AssemblyCode *assembly_code;
extern CodeObject *threeAC;

int yylex();
int yyparse();
void yyerror(char const *err){
    // printf("Not accepted\n");
};

int main(int argc, char* argv[]) {
	extern FILE *yyin;
    int retval;
    if (argc < 2) {
        std::cout<<"Usage: "<< argv[0]<<" <input file>"<<std::endl;
    }
    else {
        if (!(yyin = fopen(argv[1], "r"))) {
            std::cout<<"Error while opening file. Check if the input file is correct/exists, perhaps!"<<std::endl;
        }
        else {
            yyin = fopen(argv[1], "r");

			retval = yyparse();

            fclose(yyin);


            std::cout << "push" << std::endl;
            std::cout << "push r0" << std::endl;
            std::cout << "push r1" << std::endl;
            std::cout << "push r2" << std::endl;
            std::cout << "push r3" << std::endl;
            std::cout << "jsr main" << std::endl;
            std::cout << "sys halt" << std::endl;
            assembly_code->generateCode(threeAC, threeAC->symbolTableStack->tables);
            assembly_code->print();
            std::cout << "end" << std::endl;

        }
    }

    
    return 0;
}