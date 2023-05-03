/*
* Authors: Reese Ford, Josie D'Acquisto, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 05/02/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Constants.h"
#include "SDL_Plotter.h"

#include "Tile.h"
#include "LeftL.h"
#include "Tee.h"
#include "Line.h"
#include "RightL.h"

using namespace std;

void lineClear(vector<Tile>& others, SDL_Plotter& g);
class Current_Block {
    private:
    Block_LeftL leftL; // Block 0
    Block_RightL rightL; // Block 1
    Block_Line line; // Block 2
    Block_Tee tee; // Block 3
    int block = -1;

    public:
    Current_Block() {
        block = rand() % 4;
        if (block == 0) {
            leftL.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        else if (block == 1) {
            rightL.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        else if (block == 2) {
            line.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        else if (block == 3) {
            tee.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
    }

    void draw(SDL_Plotter& g) {
        if (block == 0) {
            leftL.draw(g);
        }
        else if (block == 1) {
            rightL.draw(g);
        }
        else if (block == 1) {
            line.draw(g);
        }
        else if (block == 1) {
            tee.draw(g);
        }
    }

    void rotateClock(vector<Tile>& others) {
        if (block == 0) {
            leftL.rotateClock(others);
        }
        else if (block == 1) {
            rightL.rotateClock(others);
        }
        else if (block == 2) {
            line.rotateClock(others);
        }
        else if (block == 3) {
            tee.rotateClock(others);
        }
    }
    void rotateCounterClock(vector<Tile>& others) {
        if (block == 0) {
            leftL.rotateCounterClock(others);
        }
        else if (block == 1) {
            rightL.rotateCounterClock(others);
        }
        else if (block == 2) {
            line.rotateCounterClock(others);
        }
        else if (block == 3) {
            tee.rotateCounterClock(others);
        }
    }

    void moveDown(vector<Tile>& others) {
        if (block == 0) {
            leftL.moveDown(others);
        }
        else if (block == 1) {
            rightL.moveDown(others);
        }
        else if (block == 2) {
            line.moveDown(others);
        }
        else if (block == 3) {
            tee.moveDown(others);
        }
    }
    void snapToBottom(vector<Tile>& others) {
        if (block == 0) {
            leftL.snapToBottom(others);
        }
        else if (block == 1) {
            rightL.snapToBottom(others);
        }
        else if (block == 2) {
            line.snapToBottom(others);
        }
        else if (block == 3) {
            tee.snapToBottom(others);
        }
    }

    void strafeToMouse(point mouseLoc, vector<Tile>& others) {
        if (block == 0) {
            leftL.strafeToMouse(mouseLoc, others);
        }
        else if (block == 1) {
            rightL.strafeToMouse(mouseLoc, others);
        }
        else if (block == 2) {
            line.strafeToMouse(mouseLoc, others);
        }
        else if (block == 3) {
            tee.strafeToMouse(mouseLoc, others);
        }
    }

    bool atBottom() {
        bool atBot = false;
        if (block == 0) {
            atBot = leftL.atBottom();
        }
        else if (block == 1) {
            atBot = rightL.atBottom();
        }
        else if (block == 2) {
            atBot = line.atBottom();
        }
        else if (block == 3) {
            atBot = tee.atBottom();
        }
        return atBot;
    }
    bool sitting(vector<Tile>& others) {
        bool sit = false;
        if (block == 0) {
            sit = leftL.sitting(others);
        }
        else if (block == 1) {
            sit = rightL.sitting(others);
        }
        else if (block == 2) {
            sit = line.sitting(others);
        }
        else if (block == 3) {
            sit = tee.sitting(others);
        }
        return sit;
    }

    void remove(vector<Tile>& others, SDL_Plotter& g) {
        if (block == 0) {
            leftL.remove(others, g);
        }
        else if (block == 1) {
            rightL.remove(others, g);
        }
        else if (block == 2) {
            line.remove(others, g);
        }
        else if (block == 3) {
            tee.remove(others, g);
        }
    }

};

int main(int argc, char** argv) {

    SDL_Plotter g(NUM_ROW, NUM_COL);

    //vector<Block_Tee> blocks(1);
    vector<Tile> squares(0);
    bool snapped = false;
    int timeCount = LEVELTIME/2;
    point mouse;
    bool gameOver = false;

    Current_Block block;

    while (!g.getQuit() && !gameOver) { // ESC

        // Rotate or Snap to Bottom
        if (g.kbhit()) {
            switch (toupper(g.getKey())) {
                case DOWN_ARROW: block.snapToBottom(squares); snapped = true;
                    break;
                case LEFT_ARROW: block.rotateCounterClock(squares);
                    break;
                case RIGHT_ARROW: block.rotateClock(squares);
                    break;
            }
        }

        // Strafe one SIZE towards the mouse cursor
        g.getMouseLocation(mouse.x, mouse.y);
        block.strafeToMouse(mouse, squares);

        // Move down one SIZE
        if (timeCount == LEVELTIME/2) {
            block.moveDown(squares);
        }

        if ((timeCount == LEVELTIME) || snapped) {
            // If at the bottom or sitting on another tile, disassociate the tiles from the block, 
            // create a new block, draw every tile, 
            // line clear the tiles, draw every tile again, reset the time count.
            if (block.atBottom() || block.sitting(squares)) {
                block.remove(squares, g);
                Current_Block block;
                for (size_t i = 0; i < squares.size(); i++) {
                    squares.at(i).draw(g);
                }
                lineClear(squares, g);
                for (size_t i = 0; i < squares.size(); i++) {
                    squares.at(i).draw(g);
                }
                timeCount = LEVELTIME / 2;
            }
            snapped = false;
        }

        // Draw the block
        block.draw(g);

        // Update the screen and timeCount
        g.update();
        g.Sleep(REFRESH);
        timeCount += REFRESH;
        if (timeCount > LEVELTIME + 1) {
            timeCount = 0;
        }

    }

    cout << endl << "Game Over" << endl;
    return 0;
}

void lineClear(vector<Tile>& others, SDL_Plotter& g) {
    vector<int> lineCounts(NUM_ROW / SIZE, 0);
    int currentY = NUM_ROW;

    for (int c = lineCounts.size() - 1; c >= 0; c--) {
        lineCounts.assign(NUM_ROW / SIZE, 0);
        for (size_t i = 0; i < others.size(); i++) {
            int currentY = others.at(i).getLoc().y;
            if (currentY > 0) {
                int index = currentY / SIZE;
                if (index < lineCounts.size()) {
                    lineCounts.at(index)++;
                }
            }
        }
        if (lineCounts.at(c) == NUM_COL / SIZE) {
            for (size_t i = 0; i < others.size(); i++) {
                currentY = others.at(i).getLoc().y;
                if (currentY == c * SIZE) {
                    others.at(i).remove(g);
                }
            }
            for (size_t i = 0; i < others.size(); i++) {
                currentY = others.at(i).getLoc().y;
                if (currentY < c * SIZE) {
                    others.at(i).moveDownLine(others);
                }
            }
            c++;
        }
    }
    //Fully delete removed tiles
    for (size_t i = 0; i < others.size(); i++) {
        if (others.at(i).isDeleted() == true) {
            others.erase(others.begin() + i);
            i--;
        }
    } 
}