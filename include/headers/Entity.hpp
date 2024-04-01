#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity{
    public:
        Entity(double p_x, double p_y, SDL_Texture* p_texture, int color, int shape)
        {
            x = p_x;
            y = p_y;
            texture = p_texture;
            currentFrame.x = 0;
            currentFrame.y = 0;
            currentFrame.w = 64;
            currentFrame.h = 64;
            this->color = color;
            this->shape = shape;
        } 
        double getX(){return x;}
        double getY(){return y;} 
        SDL_Rect getCurrentFrame(){return currentFrame;}
        SDL_Texture* getTexture(){return texture;} 
        
    private:
        double x, y;
        SDL_Rect currentFrame;
        SDL_Texture* texture;
        int color, shape;
};


