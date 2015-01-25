#pragma once
#include "Constructs.h"
class Block;

class Var : public Value
{
private:
	const Block* block;
	std::string name;
public:
	Var(const Block* block, const Type& type, const std::string& name, void* value);
	inline const Block* GetBlock(){ return block; }
	inline std::string GetName(){ return name; }
	~Var();
};

