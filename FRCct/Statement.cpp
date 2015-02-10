#include "Statement.h"


Statement::Statement(Block* root, Token* tokarr, unsigned int numTokens):
m_root(root), m_tokarr(tokarr),m_numTokens(numTokens)
{
}


Statement::~Statement()
{
}
