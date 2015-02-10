#pragma once
#include <vector>

class Compiler
{
private:
	Compiler(){}
	Compiler(const Compiler& rhs);
	void operator=(const Compiler& rhs);
	

public:
	static Compiler& GetInstance(){
		static Compiler instance;
		return instance;
	}

	void Compile();
};

