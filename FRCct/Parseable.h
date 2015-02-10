#pragma once

struct Parseable;

class IParseable{
public:
	IParseable(){}
	virtual Parseable Parse() = 0;
	virtual ~IParseable(){}
};

enum ParseableType{
	BLOCK,
	STATEMENT
};

struct Parseable
{
	IParseable* m_parseable;
	ParseableType m_type;

	Parseable(IParseable* parseable, ParseableType type) :
		m_parseable(parseable), m_type(type)
	{}
};

