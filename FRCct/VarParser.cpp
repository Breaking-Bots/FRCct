#include "VarParser.h"

bool VarParser::ShouldParse(const std::string& line){
	return std::regex_match(line, std::regex(constants::DECLARATION + constants::SPACE
		+ "=" + constants::SPACE + "\"?" + constants::IDENTIFIER + "\"?"));
}

Block* VarParser::Parse(Block& parent, Tokenizer& tokenizer){
	Type type;
	Token typeToken;
	tokenizer.NextToken(typeToken);
	type = stringTypeMap.find(typeToken.token)->second;
	Token nameToken;
	tokenizer.NextToken(nameToken);
	std::string name = nameToken.token;
	Token nullToken;
	tokenizer.NextToken(nullToken);
	Token valueToken;
	tokenizer.NextToken(valueToken);
	void* value = nullptr;

	if (valueToken.type == TokenType::INTEGER_LITERAL){
		std::istringstream buffer(valueToken.token);
		int temp;
		buffer >> temp;
		value = &temp;
	}
	else if (valueToken.type == TokenType::FLOAT_LITERAL){
		std::istringstream buffer(valueToken.token.substr(0, valueToken.token.length() - 2));
		float temp;
		buffer >> temp;
		value = &temp;
	}
	else if (valueToken.type == TokenType::DOUBLE_LITERAL){
		std::istringstream buffer(valueToken.token);
		double temp;
		buffer >> temp;
		value = &temp;
	}
	else if (valueToken.type == TokenType::STRING_LITERAL){
		std::string temp = valueToken.token;
		value = &temp;
	}
	else{
		value = parent.GetVar(valueToken.token)->GetValue();
	}

	parent.AddVar(Var(&parent, type, name, value));
	return nullptr;
}
