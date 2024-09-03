#include <iostream>
#include <random>

#include "model-snake.h"

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0, WIN_DIV);

std::vector<Block> blocks;
Block leadBlock = Block(2, 0);

int fruit_x;
int fruit_y;

int count = 0;

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

void checkPos() 
{
  if (blocks[0].x == fruit_x && blocks[0].y == fruit_y)
  {
    std::cout << ++count << std::endl;
    blocks.push_back(Block(blocks.back().x, blocks.back().y));
    placeFruit();
    paintBlocks();
    return;
  }

  for (int i = 1; i < blocks.size(); i++)
  { // Check for self collision
    if (blocks[0].x == blocks[i].x && blocks[0].y == blocks[i].y)
    {
      die();
    }
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

void die()
{
  clearWindow();
  blocks.clear();

  fruit_x = -1;
  fruit_y = -1;

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