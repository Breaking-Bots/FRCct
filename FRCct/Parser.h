#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "Lexer.h"
#include "Var.h"

class Block{
private:
	const Block* parent;
	std::vector<Block*> children;
	std::vector<Var> vars;

	Block(const Block& rhs){}
	void operator=(const Block& rhs){}
public:
	Block(const Block* parent);
	inline const Block* GetParent(){ return parent; }
	inline void AddBlock(Block* child){ children.push_back(child); }
	inline void AddVar(Var& var){ vars.push_back(var); }
	Var* GetVar(std::string name);
	virtual void Run() = 0;
	virtual ~Block();
};



class Parser
{
private:
	Parser();
	Parser(const Parser& rhs){}
	void operator=(const Parser& rhs){}
public:
	
	virtual bool ShouldParse(const std::string& line) = 0;
	virtual Block* Parse(Block& parent, Tokenizer& tokenizer) = 0;

	virtual ~Parser();
};

