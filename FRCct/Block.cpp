#include "Block.h"


Block::Block():
m_superBlock(NULL)
{
}

Block::Block(const Block* superBlock):
m_superBlock(superBlock)
{

}

Parseable Block::Parse(){
	for (IParseable& p : m_children){
		p.Parse();
	}
	return Parseable(this, ParseableType::BLOCK);
}

Block::~Block()
{
}
