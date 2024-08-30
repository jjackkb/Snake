#include <iostream>

#include "snake.h"

std::vector<Block> blocks;
Block leadBlock = Block(0, 0);

void initializeBlocks()
{
  blocks.push_back(leadBlock);
  paintBlocks();
}

void paintBlocks()
{
  paintSquare(leadBlock.x, leadBlock.y, 0);
}

// Movement

void moveUp()
{
  if (leadBlock.y - 1 >= 0)
  {
    paintSquare(leadBlock.x, leadBlock.y, 1);
    leadBlock.y -= 1;
    paintBlocks();
  }
}

void moveDown()
{
  if (leadBlock.y + 1 < WIN_DIV)
  {
    paintSquare(leadBlock.x, leadBlock.y, 1);
    leadBlock.y += 1;
    paintBlocks();
  }
}

void moveLeft()
{
  if (leadBlock.x - 1 >= 0)
  {
    paintSquare(leadBlock.x, leadBlock.y, 1);
    leadBlock.x -= 1;
    paintBlocks();
  }
}

void moveRight()
{
  if (leadBlock.x + 1 < WIN_DIV)
  {
    paintSquare(leadBlock.x, leadBlock.y, 1);
    leadBlock.x += 1;
    paintBlocks();
  }
}