#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WIN_DIV 25

// Global variables declared as extern, defined in window.cpp
extern SDL_Window *win;
extern SDL_Surface *surface;
extern bool quit;

void init();
int openWindow();
void clearWindow();

void proccessKey(SDL_KeyboardEvent *m_key);
void putPixel(int x, int y, Uint32 pixel);
void paintSquare(int x, int y, int color);

#endif // WINDOW_H