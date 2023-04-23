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
#include <vector>
#include "Constants.h"
#include "SDL_Plotter.h"

#include "Tile.h"

using namespace std;

int main(int argc, char** argv) {

    SDL_Plotter g(NUM_ROW, NUM_COL);

    char key;
    vector<Tile> squares(1);
    bool newSquare = true;
    int count = 0;
    //Block_leftL block;
    point mouse;

    while (!g.getQuit()) { // ESC

        //if (square.hitFloor()) {
        //    square.detach() // Detach all tiles from the current block
        //    Tile square; // Somehow create new block if existing block is at bottom
        //}

        if (!squares[count].atBottom()) {
            if (g.kbhit()) {
                key = g.getKey();
                switch (toupper(key)) {
                    /*case RIGHT_ARROW: block.rotateClock();
                        break;
                    case LEFT_ARROW: block.rotateOunterClock();
                        break;*/
                    case DOWN_ARROW: squares[count].moveDownFaster(squares);
                        break;
                }
            }
            g.getMouseLocation(mouse.x, mouse.y);
            squares[count].moveToMouse(mouse);
        }

        squares[count].moveDown(squares);
        squares[count].draw(g);

        g.update();
        g.Sleep(20);

        if ((squares[count].atBottom()) || (squares[count].sitting(squares))) {
            squares.emplace_back();
            count++;
        }
    }

    return 0;
}

// No Man's Land

/// Keyboard Movement of Blocks
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