/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/20/2023
*/

#include <iostream>
#include <cmath>
#include "Constants.h"
#include "SDL_Plotter.h"

#include "Tile.h"

using namespace std;

int main(int argc, char** argv) {

    SDL_Plotter g(NUM_ROW, NUM_COL);

    char key;
    Tile square;

    while (!g.getQuit()) {

        if (g.kbhit()) {
            key = g.getKey();
            switch (toupper(key)) {
                case RIGHT_ARROW: square.moveRight();
                    break;
                case LEFT_ARROW: square.moveLeft();
                    break;
            }
        }
        square.draw(g);
        square.moveDown();

        g.update();
        g.Sleep(20);
    }

    return 0;
}
