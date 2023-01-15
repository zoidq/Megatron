#pragma once
#include <SDL2/SDL.h>

class RenderWindow
{
    public:
        RenderWindow(const char* p_title, int p_width, int p_height);
        ~RenderWindow();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

};
