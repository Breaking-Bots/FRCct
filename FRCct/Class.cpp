#include "Class.h"


Class::Class(const std::string& name) :Block(NULL), name(name)
{

}

void Class::Run(){

}

Class::~Class()
{
}

bool ClassParser::ShouldParse(const std::string& line){
	return std::regex_match(line, std::regex("class" + constants::SPACE + constants::IDENTIFIER + constants::SPACE + "\\{"));
}

//TODO: make this a safe pointer
Block* ClassParser::Parse(Block& parent, Tokenizer& tokenizer){
	Token nameToken;
	tokenizer.NextToken(nameToken);
	tokenizer.NextToken(nameToken);

	std::string name = nameToken.token;

	return new Class(name);
}