#include "Statement.h"


Statement::Statement(Block* root, Token* tokarr, unsigned int numTokens):
m_root(root), m_tokarr(tokarr),m_numTokens(numTokens)
{
}

Parseable Statement::Parse(){
	return Parseable(this, ParseableType::STATEMENT);
}

Statement::~Statement()
{
}
