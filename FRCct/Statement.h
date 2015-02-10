#pragma once

class Block;
class Token;

struct Statement
{
	Block* m_root;
	Token* m_tokarr;
	unsigned int m_numTokens;
	
	Statement(Block* root, Token* tokarr, unsigned int numTokens);
	~Statement();
	Statement(const Statement& rhs) = delete;
	void operator=(const Statement& rhs) = delete;
};

