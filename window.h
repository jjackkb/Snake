#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

#define WINDOW_WIDTH 680
#define WINDOW_HEIGHT 480

class Window
{

private:

  // Global variables declared as extern, defined in window.cpp
  static SDL_Window *win;
  static SDL_Surface *surface;
  static bool quit;

  void proccessKey(SDL_KeyboardEvent *m_key);
  void putPixel(int x, int y, Uint32 pixel);
  void paintYellow();

public:
  
  Window();
  void initWindow();
  int openWindow(void);
};

#endif // WINDOW_H