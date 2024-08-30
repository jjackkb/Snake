#include <iostream>

#include "window.h"
#include "snake.h"

SDL_Window *win = nullptr;
SDL_Surface *surface = nullptr;
bool quit = false;

void init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    // Create window
    win = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (win == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    // Get window surface
    surface = SDL_GetWindowSurface(win);
}

void proccessKey(SDL_KeyboardEvent *m_key)
{
    switch (m_key->keysym.sym)
    {
    case SDLK_q:
        quit = true; break;
    case SDLK_w:
        moveUp(); break;
    case SDLK_s:
        moveDown(); break;
    case SDLK_a:
        moveLeft(); break;
    case SDLK_d:
        moveRight(); break;
    }

    //std::cout << leadBlock.x << "," << leadBlock.y << std::endl;
}

int openWindow()
{
    SDL_Event e;

    SDL_UpdateWindowSurface(win);

    initializeBlocks();

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                return 0;
            }

            switch (e.type)
            {
            case SDL_KEYDOWN:
                proccessKey(&e.key);
                break;
            }
        }
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

// Painting functions

void putPixel(int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp)
    {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
        {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        }
        else
        {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

void paintSquare(int x, int y, int m_color)
{
    x *= (WINDOW_WIDTH / WIN_DIV);
    y *= (WINDOW_HEIGHT / WIN_DIV);

    Uint32 color;

    switch (m_color) {
    case 0: color = SDL_MapRGB(surface->format, 0xff, 0xff, 0x00); break;
    case 1: color = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00); break;
    }

    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.h = y + (WINDOW_HEIGHT / WIN_DIV);
    rect.w = x + (WINDOW_WIDTH / WIN_DIV);

    if (SDL_MUSTLOCK(surface))
    {
        if (SDL_LockSurface(surface) < 0)
        {
            fprintf(stderr, "Can't lock surface: %s\n", SDL_GetError());
            return;
        }
    }

    for (int j = 0; j < WINDOW_WIDTH / WIN_DIV; ++j)
    {
        for (int h = 0; h < WINDOW_HEIGHT / WIN_DIV; ++h)
        {
            putPixel(x + j, y + h, color);
        }
    }

    if (SDL_MUSTLOCK(surface))
    {
        SDL_UnlockSurface(surface);
    }

    SDL_UpdateWindowSurfaceRects(win, &rect, 1);
}