#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "block.h"

extern std::vector<Block> blocks;

void initializeBlocks();
void paintBlocks();

#endif //SNAKE_H