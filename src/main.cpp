#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "utils/Colors.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "ShapeList.hpp"
#include <conio.h>
#include "RenderWindow.hpp"
using namespace std;

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]) {
    ShapeList<Object> shapeList;
    // while (true) {
    //     system("cls");
    //     shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
    //     shapeList.display();

    //     if (_kbhit()) {
    //         char ch = _getch();
    //         if (ch == 'x') {
    //             break;
    //         } else {
    //             ch = _getch();

    //             switch (ch) {

    //                 case 75: // Left arrow key
                        // shapeList.addRight(Object::random());

    //                     break;

    //                 case 77: // Right arrow key
    //                     shapeList.addLeft(Object::random());

    //                     break;


    //                 case 'q':
    //                     shapeList.shiftColor(RED);
    //                     break;
    //                 case 'w':
    //                     shapeList.shiftColor(GREEN);
    //                     break;
    //                 case 'e':
    //                     shapeList.shiftColor(BLUE);
    //                     break;
    //                 case 'r':
    //                     shapeList.shiftColor(YELLOW);
    //                     break;
    //                 case 'a':
    //                     shapeList.shiftShape(RECTANGLE);
    //                     break;
    //                 case 's':
    //                     shapeList.shiftShape(CIRCLE);
    //                     break;
    //                 case 'd':
    //                     shapeList.shiftShape(TRIANGLE);
    //                     break;
    //                 case 'f':
    //                     shapeList.shiftShape(DIAMOND);
    //                     break;


    //                 default:
    //                     continue;
                    
    //                 }


    //         }
    //     }
    // }

    bool gameIsRunning = true;
    SDL_Event event;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }
    if(!IMG_Init( IMG_INIT_PNG ))
    {
        cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        return EXIT_FAILURE;
    }

    RenderWindow window("SDL2", SCREEN_WIDTH, SCREEN_HEIGHT);  
    // SDL_Texture *texture = window.loadTexture("/home/med-amine/Desktop/firstSDLGame/imgs/gc.png");
    // SDL_TEXTURE textur
    // vector<Entity> entities = {
    //     Entity(0, 0, color, shape),
    //     Entity(50, 50, texture),
    //     Entity(100, 100, texture)
    // };
    // color, shape

    while(gameIsRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameIsRunning = false;
            }  
        }
        // window.clear();
        // for(Entity& entity : entities){
        //     window.render(entity);
        // }
        // window.display();
    }
    // window.cleanUp();
    IMG_Quit();
    SDL_Quit(); 
    return EXIT_SUCCESS;
}