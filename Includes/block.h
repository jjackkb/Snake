#ifndef BLOCK_H
#define BLOCK_H

struct Block {
  private:
    int x, y;

  public:
    Block(int x, int y);

    void paint();
};

#endif // BLOCK_H