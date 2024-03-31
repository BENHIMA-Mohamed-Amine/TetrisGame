#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "utils/Colors.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "ShapeList.hpp"
#include <conio.h>

int main(int argc, char* argv[]) {
    ShapeList<Object> shapeList;

    // Prints all objects of shapeList
    for (Object elem : shapeList.getArray()) {
        std::cout << "Shape: " << elem.getShape() << std::endl;
        std::cout << "Color: " << elem.getColor() << std::endl << std::endl;
    }
    


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

    // // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    //     fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    //     return 1;
    // }

    // // Create a window
    // SDL_Window *window = SDL_CreateWindow("SDL Image Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    // if (window == NULL) {
    //     fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return 1;
    // }

    // // Create a renderer
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // if (renderer == NULL) {
    //     fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 1;
    // }

    // // Load image using SDL_image
    // SDL_Surface *imageSurface = IMG_Load("C:\\Users\\medab\\Downloads\\SDL 64x Compiler\\SDL 64x Compiler\\ESTs logo.png");
    // if (imageSurface == NULL) {
    //     fprintf(stderr, "Error loading image: %s\n", IMG_GetError());
    //     SDL_DestroyRenderer(renderer);
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 1;
    // }

    // // Convert surface to texture
    // SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    // SDL_FreeSurface(imageSurface);
    // if (texture == NULL) {
    //     fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
    //     SDL_DestroyRenderer(renderer);
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 1;
    // }

    // // Clear the window
    // SDL_RenderClear(renderer);

    // // Draw the texture
    // SDL_RenderCopy(renderer, texture, NULL, NULL);

    // // Update the window
    // SDL_RenderPresent(renderer);

    // // Wait for 5 seconds
    // SDL_Delay(5000);

    // // Clean up
    // SDL_DestroyTexture(texture);
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    return 0;
}