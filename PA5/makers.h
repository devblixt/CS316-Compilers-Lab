#ifndef ASTNODE_H
#define ASTNODE_H

#include <iostream>
#include <string>

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


class ASTNode{
	public:
		std::string value;
		std::string dataType;
		std::string nodeType;
		std::string reg;
		ASTNode * left;
		ASTNode * right;
		
		virtual ThreeAC generateCode() = 0;
};

class ASTNodeInt : public ASTNode{
	public:
		ASTNodeInt(std::string val){
			this->value = val;
			this->dataType = "INT";
			this->nodeType = "CONST";
			this->left = NULL;
			this->right = NULL;
		}

		ThreeAC generateCode(){
			return ThreeAC("STOREI", value, "", reg);
		}
};

class ASTNodeFloat : public ASTNode{
	public:
		ASTNodeFloat(std::string val){
			this->value = val;
			this->dataType = "FLOAT";
			this->nodeType = "CONST";
			this->left = NULL;
			this->right = NULL;
		}

		ThreeAC generateCode(){
			return ThreeAC("STOREF", value, "", reg);
		}
};

class ASTNodeVar : public ASTNode{
	public:
		ASTNodeVar(std::string val, std::string dType){
			this->value = val;
			this->reg = val;
			this->dataType = dType;
			this->nodeType = "VAR";
			this->left = NULL;
			this->right = NULL;
		}

		ThreeAC generateCode(){
			return ThreeAC("", "", "", reg, "VAR");
		}
};

class ASTNodeOp : public ASTNode{
	public:
		ASTNodeOp(std::string op){
			this->nodeType = "OP";
			this->value = op;
			this->left = NULL;
			this->right = NULL;
		}

		ASTNodeOp(std::string op, ASTNode * lNode, ASTNode * rNode){
			this->nodeType = "OP";
			this->value = op;
			this->left = lNode;
			this->right = rNode;
		}

		ThreeAC generateCode(){
			if (value == "+"){
				if(dataType == "INT")
					return ThreeAC("ADDI", this->left->reg, this->right->reg, reg);
				else
					return ThreeAC("ADDF", this->left->reg, this->right->reg, reg);
			}
			else if (value == "-"){
				if(dataType == "INT")
					return ThreeAC("SUBI", this->left->reg, this->right->reg, reg);
				else
					return ThreeAC("SUBF", this->left->reg, this->right->reg, reg);

			}
			else if (value == "*"){
				if (dataType == "INT")
					return ThreeAC("MULTI", this->left->reg, this->right->reg, reg);
				else
					return ThreeAC("MULTF", this->left->reg, this->right->reg, reg);

			}
			else if (value == "/"){
				if (dataType == "INT")
					return ThreeAC("DIVI", this->left->reg, this->right->reg, reg);
				else
					return ThreeAC("DIVF", this->left->reg, this->right->reg, reg);

			}
			else if (value == "="){
				if (dataType == "INT")
					return ThreeAC("STOREI", this->right->reg, "", reg);
				else
					return ThreeAC("STOREF", this->right->reg, "", reg);
			}
			else 
				return ThreeAC("", "", "", "");
				
		}
};

#endif
