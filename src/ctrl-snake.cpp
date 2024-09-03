#include "model-snake.h"
#include "ctrl-snake.h" 

// Movement
void moveUp()
{
  if (blocks[0].y - 1 >= 0)
  {
    
    updateBlocks();
    blocks[0].y -= 1;
    paintBlocks();
    checkPos();
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
    paintBlocks();
    checkPos();
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
    paintBlocks();
    checkPos();
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
    paintBlocks();
    checkPos();
  }
  else
  {
    die();
  }
}