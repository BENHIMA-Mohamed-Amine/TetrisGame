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
    // SDL_Texture *texture_0_0, *texture_0_1, *texture_0_2, *texture_0_3,
    //  *texture_1_0, *texture_1_1, *texture_1_2, *texture_1_3,
    //  *texture_2_0, *texture_2_1, *texture_2_2, *texture_2_3,
    //  *texture_3_0, *texture_3_1, *texture_3_2, *texture_3_3;
    SDL_Texture *textures[4][4];
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    void cleanUp();
    void clear();
    // SDL_Texture *loadTexture(const char* p_filePath);
    void loadTexture();
    SDL_Texture* getTexture(int, int);
    void render(Entity& entity);
    void display();
};
