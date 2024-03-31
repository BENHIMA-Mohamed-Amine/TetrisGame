#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
{
    this->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        cerr<<"Error creating window: %s\n"<<SDL_GetError()<<endl;
        SDL_Quit();
    }
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        cerr<<"Error creating renderer: %s\n"<<SDL_GetError()<<endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}
