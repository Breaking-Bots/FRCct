#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Util.h"
#include "Constructs.h"

// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

enum TokenType{
	TOKEN, //token (eg. ( ) - * / + ,)
	PREPROCESSOR, // #ENTRY_TYPE
	IDENTIFIER, //first character is a letter, but following may not be
	INTEGER_LITERAL, // a number
	FLOAT_LITERAL, // a floating point number
	DOUBLE_LITERAL, // a double precision floating point number
	CHAR_LITERAL, //enclosed in single quotes
	STRING_LITERAL, //enclosed in double quotes 
	SL_COMMENT, // <- eg
	EMPTY //empty

};

struct TokenData{
	std::regex regex;
	TokenType type;

	TokenData(const std::regex& regex, const TokenType& type)
		:regex(regex), type(type){}
};

struct Token{
	std::string token;
	TokenType type;

	Token(){}

	Token(const std::string& token, const TokenType& type) 
		:token(token), type(type){}
		
};


class Tokenizer{
private: 
	std::vector<TokenData> tokenDatas;
	std::string str;
	Token* pLastToken;
	bool recede;

	std::vector<std::string> tokenList;
	Tokenizer(){}
	Tokenizer(const Tokenizer& rhs){}
	void operator=(const Tokenizer& rhs){}
public:
	explicit Tokenizer(const std::string& str);

	void NextToken(Token& out_token);
	inline bool HasNextToken(){ return !str.empty(); }

	inline void Recede(void){ if (pLastToken) recede = true; }
	~Tokenizer(){}//TODO: delete pLastToken

};

class Lexer
{
private:
	Lexer(const Lexer& rhs){}
	void operator=(const Lexer& rhs){}
public:
	Lexer();

	std::vector<std::string> ReadFile(const std::string& filename, int& lineCounter);
	std::vector<std::string> Tokenize(const std::string& filestr, int& tokenCounter);
	
	~Lexer();
};

std::string VectorToString(std::vector<std::string> vector);