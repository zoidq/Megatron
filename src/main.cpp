#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"

int main()
{
    std::cout << "Starting.." << std::endl;

    if (0 < SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

	if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "SDL2 image failed to initialize.\n";
    }

    RenderWindow window("megatr0n", 800, 600);
    SDL_Texture* logo = window.loadTexture("../res/20363253.png");
    
    bool isGameRunning = true;
    SDL_Event event;

    while (isGameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isGameRunning = false;
            }
        }

        window.clear();
        window.render(logo);
        window.display();
    }

    window.~RenderWindow();
    SDL_Quit();
    return 0;
}
