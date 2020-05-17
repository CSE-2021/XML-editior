#include "object_block.h"

ObjectBlock::ObjectBlock(QString name) : Block{name} {}

QVector<Block *> *ObjectBlock::getValue()
{
    return &blocks;
}

void ObjectBlock::addBlock(Block *blockPtr)
{
    blocks.push_back(blockPtr);
}

ObjectBlock::~ObjectBlock()
{
    for (int i = 0; i < blocks.size(); i++)
    {
        delete blocks[i];
    }
}