#include <iostream>

#include "Game.hpp"

int main()
{

    Game megatr0n;
    megatr0n.init("Megatr0n", 800, 600);


    while (megatr0n.isRunning)
    {
        megatr0n.handleEvents();
        megatr0n.update();
         
    }

    return 0;
}
