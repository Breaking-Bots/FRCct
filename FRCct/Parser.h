#pragma once

class Block;

struct Parser
{
	Parser();

	void Parse(Block* blockToParse); // recursive?

	virtual ~Parser();
	
	Parser(const Parser& rhs) = delete;
	void operator=(const Parser& rhs) = delete;
};

