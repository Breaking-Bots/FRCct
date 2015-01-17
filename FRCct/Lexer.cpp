#include "Lexer.h"


Lexer::Lexer()
{
}

std::vector<std::string> Lexer::ReadFile(const std::string &filename, int& lineCounter){
	std::ifstream file(filename);
	if (!file.good()){
		std::cerr << '\'' << filename 
			<< "\' cannot be found, or does not exist" << std::endl;
		file.close();
		exit(1);
	}
	std::string line = "";
	std::vector<std::string> res;
	while (std::getline(file, line)){
		res.push_back(line + "\n");
		lineCounter++;
	}
	file.close();
	return res;
}

std::vector<std::string> Lexer::Tokenize(const std::string& filestr, int& tokenCounter){
	std::vector<std::string> tokens;
	Tokenizer tokenizer(filestr);

	Token token("", TokenType::EMPTY);

	while (tokenizer.HasNextToken()){
		tokenizer.NextToken(token);
		tokens.push_back(token.token);
		tokenCounter++;
	}
	
	return tokens;//std::move(tokens);
}

Lexer::~Lexer()
{
}

Tokenizer::Tokenizer(const std::string& str) :str(str){

	pLastToken = new Token("", TokenType::EMPTY); // TODO: delate

	tokenList.push_back("^(\\;)");
	tokenList.push_back("^(\\=)");
	tokenList.push_back("^(\\()");
	tokenList.push_back("^(\\))");
	tokenList.push_back("^(\\.)");
	tokenList.push_back("^(\\,)");
	tokenList.push_back("^(\\{)");
	tokenList.push_back("^(\\})");


	try{
		tokenDatas.push_back(TokenData(std::regex("^(#.*)"),
			TokenType::PREPROCESSOR));
		tokenDatas.push_back(TokenData(std::regex("^([a-zA-Z][a-zA-Z0-9]*)"),
			TokenType::IDENTIFIER));
		tokenDatas.push_back(TokenData(std::regex("^((-)?[0-9]+)"),
			TokenType::INTEGER_LITERAL));
		tokenDatas.push_back(TokenData(std::regex("^(\'.\')"),
			TokenType::CHAR_LITERAL));
		tokenDatas.push_back(TokenData(std::regex("^(\".*\")"),
			TokenType::STRING_LITERAL));
		for (std::string t : tokenList){
			tokenDatas.push_back(TokenData(std::regex(t),
				TokenType::TOKEN));
		}
	}
	catch(std::regex_error& e){
		//e.what
		std::cerr << "regex error\n" << e.code() << std::endl;
		exit(1);
	}
}

//TODO: delete all tokens after done
void Tokenizer::NextToken(Token& out_token){
	str = trim(str);

	if (recede){ 
		recede = false;
		out_token = *pLastToken;
		return;
	}

	if (str.empty()){
		out_token = Token("", TokenType::EMPTY);
		pLastToken = &out_token;
		return;
	}

	for (TokenData data : tokenDatas){
		std::smatch matcher;
		bool match = std::regex_search(str, matcher, data.regex);
		if (match){
			std::string token = trim(matcher[0].str());
			str = std::regex_replace(str, data.regex, 
				"", std::regex_constants::format_first_only);

			if (data.type == TokenType::STRING_LITERAL){
				out_token =
					Token(token.substr(1, token.length() - 2)
					, TokenType::STRING_LITERAL);
			}
			else if(data.type == TokenType::CHAR_LITERAL){
				out_token =
					Token(token.substr(1, token.length() - 2)
					, TokenType::CHAR_LITERAL);
			}else{
				out_token = Token(token, data.type);
			}
			pLastToken = &out_token;
			return;
		}
	}

	std::cerr << "Could not tokenize \'" << str << "\'" << std::endl;
	system("pause");
	exit(1);
}

std::string VectorToString(std::vector<std::string> vector){
	std::string return_string;
	for (std::string str : vector){
		return_string += str + "\n";
	}
	return return_string;
}