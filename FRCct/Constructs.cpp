#include "Constructs.h"

Value::Value(const Type& type, void*& value) :type(type), value(value){

}

Value::~Value(){
	Memory::SafeDelete(value);
}

Param::Param(const Type& type, const std::string& name)
	:type(type), name(name){

}

void InitConstructs(){
	stringTypeMap.insert(StringTypeMap::value_type("string", Type::STRING));
	stringTypeMap.insert(StringTypeMap::value_type("int", Type::INTEGER));
	stringTypeMap.insert(StringTypeMap::value_type("void", Type::VOID));
}