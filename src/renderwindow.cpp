#include <iostream>
#include "RenderWindow.hpp"
#include "SDL_image.h"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height)
    :window(NULL), renderer(NULL)
{
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
    }

    const int FIRST_SUPPORTED_DRIVER = -1;

    renderer = SDL_CreateRenderer(window, FIRST_SUPPORTED_DRIVER,
        SDL_RENDERER_ACCELERATED);
   
    if (renderer == NULL) 
    {
        std::cout << "Failed to create renderer.\n" << SDL_GetError() 
            << std::endl;
    }
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
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

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::render(SDL_Texture *p_texture)
{
    SDL_Rect src_rect;
    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = 32;
    src_rect.h = 32;

    SDL_Rect dst_rect;
    dst_rect.x = 0;
    dst_rect.y = 0;
    dst_rect.w = 32;
    dst_rect.h = 32;

    SDL_RenderCopy(renderer, p_texture, &src_rect, &dst_rect);
}
