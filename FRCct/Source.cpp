#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "Constructs.h"

int main(int argc, char** argv){
	InitConstructs();
	if (argc >= 2){
		Lexer lexer;
		int lineCount = 0;
		int tokenCount = 0;
		std::vector<std::string> file = lexer.ReadFile(argv[argc - 1], lineCount);
		std::string filestr = VectorToString(file);


		std::vector<std::string> tokens = lexer.Tokenize(filestr, tokenCount);
		for (std::string str : tokens){
			std::cout << str << std::endl;
		}
	}
	else{
		std::cerr << "No files given to compile" << std::endl;
	}

	system("pause"); //TODO: remove in final build

}