#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "block.h"
#include "window.h"

extern std::vector<Block> blocks;
extern Block leadBlock;

void initializeBlocks();
void paintBlocks();
void updateBlocks();
void checkDeath();
void die();
void placeFruit();
int checkFruitPos(int x, int y);

// Movement
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

#endif // SNAKE_H