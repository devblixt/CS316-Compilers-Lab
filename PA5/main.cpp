#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iterator>
#include <sstream>
#include "wrapper.h"
#include "makers.h"
#include "parser.tab.h"

using namespace std;

extern FILE* yyin;
extern struct wrapper p;
extern map <std::string, map<std::string, wrapper> > symbolTable;
extern vector <ThreeAC> IR;
extern stringstream ss;
extern int blockCounter;
extern int labelCounter;
extern int registerCounter;
extern stack <std::string> scope;
extern map <std::string, wrapper> table;
extern std::vector <std::string> strConst, vars;

stack <int> registers;

int yylex();
int yyparse();



void yyerror(char const* msg){
	cout << "DECLARATION ERROR " << msg << "\n";
	exit(1);
}

void pushBlock();
void addSymbolTable();
string CondExprIR(ASTNode * node, string * t);
void makeIR(ASTNode * node); 
void removeAST(ASTNode * node);

void generateCMPI(string op1, string op2, string savedReg, int outputReg, int * currentReg);
void generateCMPR(string op1, string op2, string savedReg, int outputReg, int * currentReg);
void generateADD(string opcode, string op1, string op2, int * currentReg, int * addopTemp, int * mulopTemp, int * outputReg);
void generateMUL(string opcode, string op1, string op2, int * currentReg, int * temp, int* outputReg);
void generateMUL(string opcode, string op1, string op2, int * currentReg, int * temp, int* outputReg);

void printSymbolTable();
void printThreeACode();
void printTinyCode();

int main(int argc, char * argv[]) {
	if(argc > 1){
		FILE *inFile = fopen(argv[1], "r");
		if(inFile)
			yyin = inFile;
	}
	else {
		return -1;
	}

	yyparse();
	
	//printSymbolTable();
	printThreeACode();
	printTinyCode();

	return 0;
}

void pushBlock() {
	ss.str("");
	ss << "BLOCK " << ++blockCounter;
	scope.push(ss.str());
}

void addSymbolTable() {
	symbolTable[scope.top()] = table;
	table.clear();
}

string CondExprIR(ASTNode * node, string * t) {
	if(node != NULL){
		CondExprIR(node->left, t);
		CondExprIR(node->right, t);
		ss.str("");
		if(node->nodeType == "OP"){
			node->dataType = node->left->dataType;
			ss << "$T" << registerCounter++;
			node->reg = ss.str();
		}
		if(node->nodeType == "CONST")
		{
			ss << "$T" << registerCounter++;
			node->reg = ss.str();
		}
		IR.push_back(node->generateCode());
		*t = node->dataType;
		return node->reg;
	}
	*t = "NONE";
	return "";
}

void makeIR(ASTNode * node) {
	if (node != NULL){
		makeIR(node->left);
		makeIR(node->right);
		ss.str("");
		if (node->nodeType == "OP"){
			node->dataType = node->left->dataType;
			if (node->value != "="){
				ss << "$T" << registerCounter++;
				node->reg = ss.str();
			}
			else
				node->reg = node->left->reg;
		}
		if(node->nodeType == "CONST"){
			ss << "$T" << registerCounter++;
			node->reg = ss.str();
		}
		IR.push_back(node->generateCode());
	}
}

void removeAST(ASTNode * node) {
	if (node != NULL){
		removeAST(node->left);
		removeAST(node->right);
		delete node;
	}
}

void generateCMPI(string op1, string op2, string savedReg, int outputReg, int * currentReg) {
    if (op1[0] != '$' && op2[0] != '$') {
        cout << "move " << op2 << " r" << *currentReg << endl;
        outputReg = *currentReg;
        *currentReg = *currentReg + 1;
        cout << "cmpi " << op1 << " r" << outputReg << endl;
    } 
    else if (op1[0] != '$') {
        cout << "cmpi " << op1 << " r" << outputReg << endl;
    } 
    else if (op2[0] != '$') {
        cout << "cmpi r" << outputReg << " " << op2 << endl;
    } 
    else {
        cout << "cmpi r" << savedReg << " r" << outputReg;
    }
}

void generateCMPR(string op1, string op2, string savedReg, int outputReg, int * currentReg) {
    if (op1[0] != '$' && op2[0] != '$') {
        cout << "move " << op2 << " r" << *currentReg << endl;
        outputReg = *currentReg;
        *currentReg = *currentReg + 1;
        cout << "cmpr " << op1 << " r" << outputReg << endl;
    } 
    else if (op1[0] != '$')  {
        cout << "cmpr " << op1 << " r" << outputReg << endl;
    } 
    else if (op2[0] != '$')  {
        cout << "cmpr r" << outputReg << " " << op2 << endl;
    } 
    else  {
        cout << "cmpr r" << savedReg << " r" << outputReg;
    }
}

void generateADD(string opcode, string op1, string op2, int * currentReg, int * addopTemp, int * mulopTemp, int * outputReg) {
    if (op1[0] != '$') {
        cout << "move " << op1 << " r" << *currentReg << endl;
        *addopTemp = *currentReg - 1;
        *currentReg = *currentReg + 1;

        if (op2[0] != '$')  {
            cout << opcode << " " << op2 << " r" << *currentReg - 1 << endl;
            registers.push(*currentReg - 1);
        } 
        else  {
            cout << opcode << " r" << *addopTemp << " r" << *currentReg - 1 << endl;
            if (!registers.empty()) {
                registers.pop();
            }
            registers.push(*currentReg - 1);
        }
        *outputReg = *currentReg - 1;
        *addopTemp = *currentReg - 1;
    } 
    else  {
        if (op2[0] != '$')  {
            cout << opcode << " " << op2 << " r" << *currentReg - 1 << endl;
            *outputReg = *currentReg - 1;
        } 
        else  {
            while (!registers.empty()) {
                *addopTemp = registers.top();
                registers.pop();
            }
            cout << opcode << " r" << *currentReg - 1 << " r" << *addopTemp << endl;
            *outputReg = *addopTemp;
            registers.push(*addopTemp);
        }
    }
    *mulopTemp = *addopTemp;
}

void generateMUL(string opcode, string op1, string op2, int * currentReg, int * temp, int * outputReg) {
    if (op1[0] != '$')  {
        cout << "move " << op1 << " r" << *currentReg << endl;
        *temp = *currentReg - 1;
        *currentReg = *currentReg + 1;

        if (op2[0] != '$')  {
            cout << opcode << " " << op2 << " r" << *currentReg - 1 << endl;
            registers.push(*currentReg - 1);
        } 
        else  {
            cout << opcode << " r" << *temp << " r" << *currentReg - 1 << endl;
            if (!registers.empty()) {
                registers.pop();
            }
            registers.push(*currentReg - 1);
        }
        *outputReg = *currentReg - 1;
        *temp = *currentReg - 1;
    } 
    else {
        if (op2[0] != '$') {
            cout << opcode << " " << op2 << " r" << *currentReg - 1 << endl;
            *outputReg = *currentReg - 1;
        } 
        else {
            while (!registers.empty()) {
                *temp = registers.top();
                registers.pop();
            }
            cout << opcode << " r" << *currentReg - 1 << " r" << *temp << endl;
            *outputReg = *temp;
            registers.push(*temp);
        }
    }
}

void printSymbolTable() {
	for(map <string, map<string, wrapper> >::iterator itr = symbolTable.begin(); itr != symbolTable.end(); ++itr){
		cout << "Symbol table " << itr->first << "\n";
		map <string, wrapper> &internal_map = itr->second;
		for(map <string, wrapper>::iterator itr2 = internal_map.begin(); itr2 != internal_map.end(); ++itr2){
			p = itr2->second;
			if(p.value[0] == "STRING")
				cout << "name " << itr2->first << " type " << p.value[0] << " value " << p.value[1] << "\n";
			else
				cout << "name " << itr2->first << " type " << p.value[0] << "\n";
		}
		cout << "\n";
	}
}

void printThreeACode() {
	cout << ";IR Code" << "\n";
	for(vector <ThreeAC>::iterator itr = IR.begin(); itr != IR.end(); itr++){
		itr->printThreeAC();
	}
}

void printTinyCode() {
	cout << ";Tiny Code" << "\n";
	for (vector<string>::iterator itr = vars.begin(); itr != vars.end(); ++itr) {
	    cout << "var " << *itr << "\n";
	}

	for (vector<string>::iterator itr = strConst.begin(); itr != strConst.end(); ++itr) {
	    cout << *itr << "\n";
	}

	int currentRegister = 0;
	int outputRegister = 0;
	int addopTemp = 0;
	int mulopTemp = 0;

	string code, op1, op2, result, savedReg;
	for (vector<ThreeAC>::iterator itr = IR.begin(); itr != IR.end(); ++itr) {
	    code = itr->opCode;
	    op1 = itr->operand1;
	    op2 = itr->operand2;
	    result = itr->result;

	    if (itr->cmpType == "SAVE") {
	        savedReg = outputRegister;
	    } 
	    else if (itr->cmpType == "VAR") {
	        savedReg = result;
	    }
	    if (code == "WRITEI") {
	        cout << "sys writei " << result << endl;
	    } 
	    else if (code == "WRITEF") {
	        cout << "sys writer " << result << endl;
	    } 
	    else if (code == "WRITES") {
	        cout << "sys writes " << result << endl;
	    } 
	    else if (code == "READI") {
	        cout << "sys readi " << result << endl;
	    } 
	    else if (code == "READF") {
	        cout << "sys readr " << result << endl;
	    } 
	    else if (code == "JUMP") {
	        cout << "jmp " << result << endl;
	    } 
	    else if (code == "GT") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jgt " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "GE") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jge " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "LT") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jlt " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "LE") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jle " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "NE") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jne " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "EQ") {
	        if (itr->cmpType == "INT") {
	            generateCMPI(op1, op2, savedReg, outputRegister, &currentRegister);
	        } 
	        else {
	            generateCMPR(op1, op2, savedReg, outputRegister, &currentRegister);
	        }
	        cout << "jeq " << result << endl;
	        while (!registers.empty()) 
	            registers.pop();
	    } 
	    else if (code == "LABEL") {
	        cout << "label " << result << endl;
	    } 
	    else if (code == "STOREI" || code == "STOREF") {
	        if (result[0] != '$'){
	            if (op1[0] != '$'){
	                cout << "move " << op1 << " r" << currentRegister << endl;
	                cout << "move r" << currentRegister << " " << result << endl;
	                currentRegister = currentRegister + 1;
	            } 
	            else {
	                cout << "move r" << outputRegister << " " << result << endl;
	                while (!registers.empty()) registers.pop();
	            }
	        } 
	        else {
	            cout << "move " << op1 << " r" << currentRegister << endl;
	            outputRegister = currentRegister;
	            registers.push(currentRegister);
	            currentRegister++;
	        }
	    }
	    else if (code == "ADDI") {
	        generateADD("addi", op1, op2, &currentRegister, &addopTemp, &mulopTemp, &outputRegister);
	    } 
	    else if (code == "ADDF") {
	        generateADD("addr", op1, op2, &currentRegister, &addopTemp, &mulopTemp, &outputRegister);
	    }
	    else if (code == "SUBI") {
	        generateADD("subi", op1, op2, &currentRegister, &addopTemp, &mulopTemp, &outputRegister);
	    } 
	    else if (code == "SUBF") {
	        generateADD("subr", op1, op2, &currentRegister, &addopTemp, &mulopTemp, &outputRegister);
	    }
	    else if (code == "MULTI") {
	        generateMUL("muli", op1, op2, &currentRegister, &mulopTemp, &outputRegister);
	    } 
	    else if (code == "MULTF") {
	        generateMUL("mulr", op1, op2, &currentRegister, &mulopTemp, &outputRegister);
	    }
	    else if (code == "DIVI") {
	        generateMUL("divi", op1, op2, &currentRegister, &mulopTemp, &outputRegister);
	    } 
	    else if (code == "DIVF") {
	        generateMUL("divr", op1, op2, &currentRegister, &mulopTemp, &outputRegister);
	    }
	}
	cout << "sys halt";
}
