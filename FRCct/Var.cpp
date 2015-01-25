#include "Var.h"
#include "Parser.h"

Var::Var(const Block* block, const Type& type, const std::string& name, void* value)
	:Value(type, value), block(block), name(name)
{
}


Var::~Var()
{
}

