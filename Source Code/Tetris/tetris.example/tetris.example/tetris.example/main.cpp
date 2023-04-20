//
//  main.cpp
//  tetris.example
//
//  Created by josietwirls on 3/21/23.
// Test Edit to be sure - Reese

#include <iostream>
#include "constant.h"
#include "tile.h"
#include "SDL_Plotter.h"
const int SIZE = 50;


int main() {
    
    SDL_Plotter g(NUM_ROW, NUM_COL);

    char key;
    tile square;
    
    while (!g.getQuit())
    {
        if(g.kbhit()){
            key = g.getKey();
            switch(toupper(key)){
                case RIGHT_ARROW: square.moveRight();
                    break;
                    
                case LEFT_ARROW: square.moveLeft();
                    break;
            }
        }
        square.draw(g);
        square.move();
        g.update();
        g.Sleep(20);
        
    }
    return 0;
}
