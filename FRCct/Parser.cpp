#include "Parser.h"
Block::Block(const Block* parent):parent(parent){}


Block::~Block(){}

Var* Block::GetVar(std::string name){
	//TODO: check super blocks first

	for (Var v : vars){
		if (v.GetName() == name){
			return new Var(v);
		}
	}

	std::cerr << "\'" + name + "\' not found" << std::endl;
	return nullptr;
}