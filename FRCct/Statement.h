#pragma once
#include "Parseable.h"

class Block;
class Token;

struct Statement: public IParseable
{
	Block* m_root;
	Token* m_tokarr;
	unsigned int m_numTokens;
	
	Statement(Block* root, Token* tokarr, unsigned int numTokens);
	Parseable Parse() sealed;

	~Statement();
	Statement(const Statement& rhs) = delete;
	void operator=(const Statement& rhs) = delete;
};

