#include <iostream>
#include <SDL.h>

#include "snake.h"
#include "window.h"  // Include only the header, not the cpp

int main(void) 
{
    std::cout << "Hello Snake" << std::endl;
    
    Window win;

    return win.openWindow();
}