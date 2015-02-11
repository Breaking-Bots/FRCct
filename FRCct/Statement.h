#pragma once
#include "Parseable.h"
#include <regex>
#include "Constructs.h"

static const unsigned char ST_FLAG_DECLARATION = 0x01;
static const unsigned char ST_FLAG_ASSIGNMENT = 0x02;
static const unsigned char ST_FLAG_FUNCTION_CALL = 0x04;
static const unsigned char ST_FLAG_EXPRESSION = 0x08;

struct StatementBitSet{
	unsigned char flags;
};

struct StatementData{
	std::regex regex;
	StatementBitSet types;

	StatementData(const std::regex& regex, 
		const StatementBitSet& flags):
		regex(regex), types(flags)
	{}
};

class Block;
class Token;

struct Statement: public IParseable
{
	static std::vector<StatementData> statementDatas;

	static void InitFlags(){
		statementDatas.push_back(StatementData(std::regex(constants::DECLARATION), StatementBitSet()));
	}

	Block* m_root;
	Token* m_tokarr;
	unsigned int m_numTokens;
	
	Statement(Block* root, Token* tokarr, unsigned int numTokens);
	Parseable Parse() sealed;

	~Statement();
	Statement(const Statement& rhs) = delete;
	void operator=(const Statement& rhs) = delete;
};

