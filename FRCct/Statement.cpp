#include "Statement.h"
#include "Lexer.h"

Statement::Statement(Block* root, Token* tokarr, unsigned int numTokens):
m_root(root), m_tokarr(tokarr),m_numTokens(numTokens)
{
}

Parseable Statement::Parse(){
	
	std::string strline;
	for (unsigned int i = 0; i < m_numTokens; i++){
		strline += m_tokarr[i].token + " ";
		if (m_tokarr[i].type = TokenType::IDENTIFIER){

		}
	}

	return Parseable(this, ParseableType::STATEMENT);
}

Statement::~Statement()
{
}
