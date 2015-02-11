#pragma once

struct Parseable;

class IParseable{
public:
	IParseable():m_parsed(false), m_hasUnresolvedExternalSymbols(false){}
	bool m_parsed;
	bool m_hasUnresolvedExternalSymbols;

	virtual Parseable Parse() = 0;
	virtual ~IParseable(){}
};

enum ParseableType{
	BLOCK,
	CLASS,
	STRUCT,
	COMMAND,
	SUBSYSTEM,
	PID_SUBSYSTEM,
	FUNCTION,
	LOGIC_IF,
	LOGIC_ELSE_IF,
	LOGIC_ELSE,
	FOR_LOOP,
	WHILE_LOOP,
	DO_LOOP,
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

