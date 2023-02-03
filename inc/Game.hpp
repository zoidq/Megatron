#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

class Game
{
    public:
        Game();
        ~Game();

        void init (const char* p_title, int p_width, int p_height);
        void handleEvents();
        void update();
        void render();
        SDL_Texture* loadTexture(const char* p_filePath);
        bool isRunning;
        SDL_Renderer* renderer;
        SDL_Event event;

    private:
        SDL_Window* window;

};
