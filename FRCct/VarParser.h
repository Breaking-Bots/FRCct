#pragma once
#include "Parser.h"

class VarParser : public Parser{
private:
	
public:
	virtual bool ShouldParse(const std::string& line);
	virtual Block* Parse(Block& parent, Tokenizer& tokenizer);
};
