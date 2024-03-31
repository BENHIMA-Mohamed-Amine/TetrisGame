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

void RenderWindow::loadTexture()
{
    textures[0][0] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\RectangleRed.png");
    textures[0][1] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\CircleRed.png"); 
    textures[0][2] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\TriangleRed.png"); 
    textures[0][3] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\DiamondRed.png");

    textures[1][0] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\RectangleGreen.png"); 
    textures[1][1] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\CircleGreen.png"); 
    textures[1][2] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\TriangleGreen.png"); 
    textures[1][3] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\DiamondGreen.png");

    textures[2][0] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\RectangleBlue.png"); 
    textures[2][1] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\CircleBlue.png"); 
    textures[2][2] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\TriangleBlue.png"); 
    textures[2][3] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\DiamondBlue.png");

    textures[3][0] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\RectangleYellow.png"); 
    textures[3][1] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\CircleYellow.png"); 
    textures[3][2] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\TriangleYellow.png"); 
    textures[3][3] = IMG_LoadTexture(renderer, "C:\\Users\\medab\\OneDrive\\Documents\\Cursus-Academic\\ENSET\\Structure de donnee\\TetrisGame\\assets\\DiamondYellow.png");

    if(textures[0][0] == nullptr)
        cerr<<"can't load a image "<<  SDL_GetError()<<endl;
}

SDL_Texture* RenderWindow::getTexture(int i, int j)
{
    return textures[i][j];
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::render(Entity& p_entity){
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;  

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst); 
}