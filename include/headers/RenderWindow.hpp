#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.hpp"
using namespace std;

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    void cleanUp();
    void clear();
    SDL_Texture *loadTexture(const char* p_filePath);
    void render(Entity& entity);
    void display();
};
