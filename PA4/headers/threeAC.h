#ifndef THREEAC_H
#define THREEAC_H

#include <iostream>
#include <string>

class ThreeAC{
	public:
		std::string opCode;
		std::string operand1, operand2, result;
		std::string cmpType;

		ThreeAC(std::string op, std::string op1, std::string op2, std::string res){
			this->opCode = op;
			this->operand1 = op1;
			this->operand2 = op2;
			this->result = res;
			this->cmpType = "NONE";
		}

		ThreeAC(std::string op, std::string op1, std::string op2, std::string res, std::string cmp){
			this->opCode = op;
			this->operand1 = op1;
			this->operand2 = op2;
			this->result = res;
			this->cmpType = cmp;
		}

		void printThreeAC(){
			if(opCode != ""){
				std::cout << ";" << opCode;
				if(operand1 != "")
					std::cout << " " << operand1;
				if(operand2 != "")
					std::cout << " " << operand2;
				std::cout << " " << result << "\n";
			}
		}
};

#endif
