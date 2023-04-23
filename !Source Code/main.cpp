/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/21/2023
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
    point mouse;

    while (!g.getQuit()) { // ESC

        //if (square.hitFloor()) {
        //    square.detach() // Detach all tiles from the current block
        //    Tile square; // Somehow create new block if existing block is at bottom
        //}

        //if (g.kbhit()) {
        //    key = g.getKey();
        //    switch (toupper(key)) {
        //        case RIGHT_ARROW: square.moveRight();
        //            break;
        //        case LEFT_ARROW: square.moveLeft();
        //            break;
        //        // case SPACE: square.rotateClock();
        //        // case LEFT_CTRL: sqaure.rotateCounterClock();
        //        // case DOWN_ARROW: square.drop();
        //        // MAYBE: case RIGHT_SHIFT square.hold(); // "Hold" the current tile and spawn the next one
        //    }
        //}
        g.getMouseLocation(mouse.x, mouse.y);

        square.draw(g);
        square.moveToMouse(mouse);
        square.moveDown();

        //if (square.hitFloor()) {
        //    // Check all rows for complete-ness
        //    // This I have no idea how to do
        //}

        g.update();
        g.Sleep(20);
    }

    return 0;
}
