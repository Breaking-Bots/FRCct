#include "Function.h"


Function::Function(const Block* parent, const std::string& name, const Type& type,
	const std::vector<Param>& params)
	:Block(parent), name(name), type(type), params(params)
{
}

void Function::Run(){
	Invoke();
}

void Function::Invoke(int argn, Value* values){

}

Function::~Function()
{
}

bool FunctionParser::ShouldParse(std::string line){
	return std::regex_match(line, std::regex(constants::DECLARATION + constants::SPACE + "\\((" + constants::DECLARATION + ")*\\)" + constants::SPACE + "\\{"));
}

Block* FunctionParser::Parse(Block& parent, Tokenizer& tokenizer){
	Token typeToken;
	Token nameToken;
	Token nullToken;


	tokenizer.NextToken(typeToken);
	std::string type = typeToken.token;
	tokenizer.NextToken(nameToken);
	std::string name = nameToken.token;
	tokenizer.NextToken(nullToken);

	Token first;
	tokenizer.NextToken(first);

	std::vector<Param> params;
	if (first.token != ")"){
		std::string paramData[2] = { first.token, nullptr };

		while (tokenizer.HasNextToken()){
			Token token;
			tokenizer.NextToken(token);
			if (token.token == ")"){
				break;
			}

			if (paramData[0] == ""){
				paramData[0] = token.token;
			}
			else{
				paramData[1] = token.token;

				params.push_back(Param(stringTypeMap.find(paramData[0])->second, paramData[1]));

				std::fill_n(paramData, 2, "");
			}
		}
	}

	Type returnType = stringTypeMap.find(type)->second;

	return new Function(&parent, name, returnType, params);
}