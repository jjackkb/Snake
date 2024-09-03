#include <iostream>
#include <SDL.h>

#include "main.h"
#include "window.h" 
#include "model-snake.h"

int main(void) 
{
    
    init();
    initializeBlocks();

    return openWindow();
}