#pragma once
#include <vector>
#include "Parseable.h"


class Block: public IParseable
{
public:
	static Block& GlobalBlock(){
		static Block globalBlock;
		return globalBlock;
	}

	const Block* m_superBlock;
	std::vector<Parseable> m_children;
	bool m_parsed;
	bool m_hasExternalSymbols;

	Parseable Parse() sealed;

	explicit Block(const Block* superBlock);
	~Block();
	void operator=(const Block& rhs) = delete;

private:
	Block();	
};

