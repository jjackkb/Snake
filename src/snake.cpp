#include "snake.h"

std::vector<Block> blocks;

void initializeBlocks() {
  blocks.push_back(Block(0,0));
  blocks.push_back(Block(1,0));
  blocks.push_back(Block(2,0));
}

void paintBlocks() {
  for (int i = 0; i < blocks.size(); i++) {
    blocks[i].paint();
  }
}