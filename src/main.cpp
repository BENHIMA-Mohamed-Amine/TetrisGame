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

int shapeListSize(ShapeList<Object> shapeList){
    int i=0;
    for (Object elem : shapeList.getArray())
    {
        i++;
    }
    return i;
}

int main(int argc, char* argv[]) {


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
    //                     shapeList.addRight(Object::random());

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
    window.loadTexture();
    ShapeList<Object> shapeList;

// shapeList is accessible here with its last value from the loop

    
    int gap=0;

    vector<Entity> entities;
    for (Object elem : shapeList.getArray())
    {
        int color = elem.getColor(), shape = elem.getShape();
        entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
        gap += 80;
    }
    Object* suggestion = Object::random();
    entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
    
    int firstTime = 1;
    while (gameIsRunning)
    {
        if(firstTime){
            shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
            cout<<"Score= "<<shapeList.score<<endl;
            entities.clear();
            gap=0;
            for (Object elem : shapeList.getArray())
            {
                int color = elem.getColor(), shape = elem.getShape();
                entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                gap += 80;
            }
            suggestion = Object::random();
            entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
            firstTime = 0;
        }
        if (entities.size() >= 11) {
            cout<<"Game Over"<<endl;
            gameIsRunning = false; // Exit the game loop
            break; // Exit the loop immediately
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT: // Right arrow key
                        shapeList.addRight(suggestion);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        suggestion = Object::random();
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_LEFT: // Left arrow key
                        shapeList.addLeft(suggestion);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        suggestion = Object::random();
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_q:
                        shapeList.shiftColor(RED);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_w:
                        shapeList.shiftColor(GREEN);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_e:
                        shapeList.shiftColor(BLUE);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_r:
                        shapeList.shiftColor(YELLOW);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_a:
                        shapeList.shiftShape(RECTANGLE);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_s:
                        shapeList.shiftShape(CIRCLE);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_d:
                        shapeList.shiftShape(TRIANGLE);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_f:
                        shapeList.shiftShape(DIAMOND);
                        shapeList.checkIdenticalShapes(); // check if random generated objects are by chance identical by color or by shape
                        cout<<"Score= "<<shapeList.score<<endl;
                        entities.clear();
                        gap=0;
                        for (Object elem : shapeList.getArray())
                        {
                            int color = elem.getColor(), shape = elem.getShape();
                            entities.push_back(Entity(100+gap, 250, window.getTexture(color, shape), color, shape));
                            gap += 80;
                        }
                        entities.push_back(Entity(90, 100, window.getTexture(suggestion->getColor(), suggestion->getShape()), suggestion->getColor(), suggestion->getShape()));
                        break;
                    case SDLK_x:
                        gameIsRunning = false;
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear();

        for (Entity& entity : entities) {
            window.render(entity);
        }

        window.display();
    }

    window.cleanUp();
    IMG_Quit();
    SDL_Quit(); 
    return EXIT_SUCCESS;
}