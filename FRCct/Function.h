#pragma once
#include "Parser.h"
#include "Constructs.h"
#include <array>
class Function: public Block
{
private:
	std::string name;
	Type type;
	std::vector<Param> params;
	Value returnValue;

	Function(const Function& rhs) :Block(NULL){}
	void operator=(const Function& rhs){}
public:
	Function(const Block* parent, const std::string& name, const Type& type,
		const std::vector<Param>& params);
	virtual void Run();
	void Invoke(int argn = 0, Value* values = NULL);
	inline std::string GetName(){ return name; }

	virtual ~Function();
};

class FunctionParser :public Parser{
private:

public:
	virtual bool ShouldParse(std::string line);

	virtual Block* Parse(Block& parent, Tokenizer& tokenizer);
};