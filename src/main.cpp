#include <iostream>
#include <SDL.h>

#include "main.h"
#include "window.h"  // Include only the header, not the cpp

int main(void) 
{
    std::cout << "Hello main" << std::endl;
    
    init();

    return openWindow();
}