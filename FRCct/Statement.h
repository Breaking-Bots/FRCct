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
	StatementBitSet(unsigned char flags) :flags(flags){}
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
		statementDatas.push_back(StatementData(
			std::regex("^(" + constants::DECLARATION + constants::SPACE + "\\;)"),
			StatementBitSet(ST_FLAG_DECLARATION)));
		statementDatas.push_back(StatementData(
			std::regex("\\="),
			StatementBitSet(ST_FLAG_ASSIGNMENT)));
		statementDatas.push_back(StatementData(
			std::regex(constants::IDENTIFIER + constants::SPACE + "\\(.*\\)"),
			StatementBitSet(ST_FLAG_FUNCTION_CALL)));
		statementDatas.push_back(StatementData(
			std::regex("([\\+\\-\\*\\/\\%\\^\\|\\&\\~\\<\\>\\!])"), //TODO: allow arithmetic
			StatementBitSet(ST_FLAG_EXPRESSION)));
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

