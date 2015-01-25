#pragma once
#include "Util.h"
#include <string>
#include <map>

namespace constants{
	const std::string IDENTIFIER = "[a-zA-Z][a-zA-Z0-9]*";
	const std::string SPACE = "\\s+";
	const std::string DECLARATION = "[a-zA-Z][a-zA-Z0-9]*\\s+[a-zA-Z][a-zA-Z0-9]*";
}

enum Type{
	STRING,
	INTEGER,
	VOID,
};

typedef std::map<std::string, Type> StringTypeMap;
static StringTypeMap stringTypeMap;

void InitConstructs();

class Value{

private:
	Type type;
	void* value;

	//Value(const Value& rhs){}
	void operator=(const Value& rhs){}
public:
	Value(){}
	Value(const Type& type, void*& value);

	inline Type GetType(){ return type; }

	inline void* GetValue(){ return value; }
	inline void SetValue(void* obj){ value = obj; }

	virtual ~Value();
};

class Param{
private:
	std::string name;
	Type type;
	//Param(const Param& rhs){}
	void operator=(const Param& rhs){}
public:
	Param(){}
	Param(const Type& type, const std::string& name);

	inline std::string GetName(){ return name; }
	inline Type GetType(){ return type; }
};