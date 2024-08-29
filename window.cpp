#include "window.h"

// Define static members of the Window class
bool Window::quit = false;

SDL_Window *Window::win = nullptr;
SDL_Surface *Window::surface = nullptr;

Window::Window()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    // Create window
    win = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (win == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    // Get window surface
    surface = SDL_GetWindowSurface(win);
}

void Window::proccessKey(SDL_KeyboardEvent *m_key)
{
    switch (m_key->keysym.sym)
    {
    case SDLK_q:
        quit = true;
        break;
    }
}

int Window::openWindow()
{
    SDL_Event e;

    SDL_UpdateWindowSurface(win);

    paintYellow(); // Correct usage, since it's a member function of Window class

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
            case SDL_KEYUP:
                proccessKey(&e.key);
                break;
            }
        }
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

void Window::putPixel(int x, int y, Uint32 pixel)
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

void Window::paintYellow()
{
    int x, y;
    Uint32 yellow;

    yellow = SDL_MapRGB(surface->format, 0xff, 0xff, 0x00);

    x = 400;
    y = 200;
    
    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.h = 600;
    rect.w = 400;

    if (SDL_MUSTLOCK(surface))
    {
        if (SDL_LockSurface(surface) < 0)
        {
            fprintf(stderr, "Can't lock surface: %s\n", SDL_GetError());
            return;
        }
    }

    putPixel(x, y, yellow);

    if (SDL_MUSTLOCK(surface))
    {
        SDL_UnlockSurface(surface);
    }

    SDL_UpdateWindowSurfaceRects(win, &rect, 1);
}