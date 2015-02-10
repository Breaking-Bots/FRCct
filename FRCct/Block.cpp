#include "Block.h"


Block::Block():
IParseable(), m_superBlock(NULL), m_parsed(false), m_hasExternalSymbols(false)
{
}

Block::Block(const Block* superBlock):
m_superBlock(superBlock), m_parsed(false), m_hasExternalSymbols(false)
{

}

Parseable Block::Parse(){
	return Parseable(this, ParseableType::BLOCK);
}

Block::~Block()
{
}
