#pragma once
#include "Parser.h"
#include "Constructs.h"

class Class :
	public Block
{
private:
	std::string name;

	Class(const Class& rhs):Block(NULL){}
	void operator=(const Class& rhs){}

public:
	Class(const std::string& name);
	virtual void Run();

	inline std::string getName(){ return name; }

	virtual ~Class();
};

class ClassParser : public Parser{
private:

public:
	virtual bool ShouldParse(const std::string& line);
	virtual Block* Parse(Block& parent, Tokenizer& tokenizer);
};