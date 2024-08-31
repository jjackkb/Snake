#include <iostream>
#include <random>

#include "snake.h"

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0, WIN_DIV);

std::vector<Block> blocks;
Block leadBlock = Block(2, 0);

int fruit_x;
int fruit_y;

void initializeBlocks()
{
  blocks.push_back(leadBlock);
  blocks.push_back(Block(1, 0));
  blocks.push_back(Block(0, 0));

  placeFruit();

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

  if (blocks[0].x == fruit_x && blocks[0].y == fruit_y)
  {
    blocks.push_back(Block(blocks.back().x, blocks.back().y));
    placeFruit();
    paintBlocks();
  }
}

void checkDeath()
{
  for (int i = 1; i < blocks.size(); i++)
  { // Check for self collision
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

// Fruit control

void placeFruit()
{
  int x, y;

  do
  {
    x = dist(rng);
    y = dist(rng);

  } while (!checkFruitPos(x, y));

  fruit_x = x;
  fruit_y = y;

  paintSquare(x, y, 2);
}

int checkFruitPos(int x, int y)
{
  for (Block b : blocks)
  {
    if (b.x == x && b.y == y)
      return 0;
  }

  return 1;
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