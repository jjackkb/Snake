#include "block.h"
#include "window.h"

int x, y;

Block::Block(int x_m, int y_m) {
  x = x_m;
  y = y_m;  
}

void Block::paint() {
  paintYellowSquare(x, y);
}