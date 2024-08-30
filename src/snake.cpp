#include <iostream>

#include "snake.h"

std::vector<Block> blocks;
Block leadBlock = Block(2, 0);

void initializeBlocks()
{
  blocks.push_back(leadBlock);
  blocks.push_back(Block(1, 0));
  blocks.push_back(Block(0, 0));

  paintBlocks();
}

void paintBlocks()
{
  for (Block b : blocks)
  {
    paintSquare(b.x, b.y, 0);
  }
}

void updateBlocks()
{
  paintSquare(blocks.back().x, blocks.back().y, 1);

  for (int i = blocks.size() - 1; i > 0; i--)
  {
    blocks[i].x = blocks[i - 1].x;
    blocks[i].y = blocks[i - 1].y;
  }
}

void checkDeath() {
  for (int i = 1; i < blocks.size(); i++) { // Check for self collision
    if (blocks[0].x == blocks[i].x && blocks[0].y == blocks[i].y)
    {
      die();
    }
  }
}

void die()
{
  for (Block b : blocks)
    paintSquare(b.x, b.y, 1);

  blocks.clear();
  initializeBlocks();
}

// Movement

void moveUp()
{
  if (blocks[0].y - 1 >= 0)
  {
    updateBlocks();
    blocks[0].y -= 1;
    checkDeath();
    paintBlocks();
  }
  else
  {
    die();
  }
}

void moveDown()
{
  if (blocks[0].y + 1 < WIN_DIV)
  {
    updateBlocks();
    blocks[0].y += 1;
    checkDeath();
    paintBlocks();
  }
  else
  {
    die();
  }
}

void moveLeft()
{
  if (blocks[0].x - 1 >= 0)
  {
    updateBlocks();
    blocks[0].x -= 1;
    checkDeath();
    paintBlocks();
  }
  else
  {
    die();
  }
}

void moveRight()
{
  if (blocks[0].x + 1 < WIN_DIV)
  {
    updateBlocks();
    blocks[0].x += 1;
    checkDeath();
    paintBlocks();
  }
  else
  {
    die();
  }
}