#include "SDL_render.h"
#include "Game.hpp"

// constructor
Game::Game()
{
    window = nullptr;
    renderer = nullptr;
}


// destructor
Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


void Game::init(const char* p_title, int p_width, int p_height)
{
    if (0 < SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        exit (-1);
    }

	if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "SDL2 image failed to initialize.\n";
        exit (-1);
    }

    window = SDL_CreateWindow(p_title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        p_width,
        p_height,
        SDL_WINDOW_SHOWN);

    if (NULL == window)
    {     
        std::cout << "Failed to create window.\n" << SDL_GetError() 
            << std::endl;
        exit(-1);
    }

    const int FIRST_SUPPORTED_DRIVER = -1;

    renderer = SDL_CreateRenderer(window, FIRST_SUPPORTED_DRIVER,
        SDL_RENDERER_ACCELERATED);
   
    if (renderer == NULL) 
    {
        std::cout << "Failed to create renderer.\n" << SDL_GetError() 
            << std::endl;
        exit(-1);
    }

    SDL_Texture* texture = loadTexture("../res/20363253.png");
    SDL_RenderCopy(renderer, texture, 0, 0);
    isRunning = true;
}


void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}


SDL_Texture* Game::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    if (NULL == texture)
    {
        std::cout << "Failed to load texture: " << SDL_GetError() 
            << std::endl;
    }

    return texture;
}


void Game::update()
{
    SDL_RenderPresent(renderer);
}


void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
