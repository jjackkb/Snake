#ifndef MODEL_SNAKE_H
#define MODEL_SNAKE_H

#include <vector>

#include "block.h"
#include "window.h"

extern std::vector<Block> blocks;
extern Block leadBlock;

void initializeBlocks();
void paintBlocks();
void checkPos();
void updateBlocks();
void die();
void placeFruit();
int checkFruitPos(int x, int y);

#endif //MODEL_SNAKE_H