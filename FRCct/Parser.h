#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<regex>
#include "Lexer.h"

class Block{
private:
	Block* parent;
	std::vector<Block*> children;

	Block(const Block& rhs){}
	void operator=(const Block& rhs){}
public:
	Block(Block* parent);
	inline Block* GetParent(){ return parent; }
	inline void AddBlock(Block* child){ children.push_back(child); }
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
	virtual Block* Parse(const Block& parent, Tokenizer& tokenizer) = 0;

	virtual ~Parser();
};

