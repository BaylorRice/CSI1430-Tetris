/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/24/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Constants.h"
#include "SDL_Plotter.h"

#include "Tile.h"
#include "LeftL.h"

using namespace std;

void lineClear(vector<Tile>& others, SDL_Plotter& g);

int main(int argc, char** argv) {

    SDL_Plotter g(NUM_ROW, NUM_COL);

    char key;
    vector<Block_LeftL> blocks(1);
    vector<Tile> squares(0);
    bool nextBlockReady = true;
    int count = 0;
    point mouse;

    while (!g.getQuit()) { // ESC

        if (g.kbhit()) {
            switch (toupper(g.getKey())) {
                case DOWN_ARROW: blocks.back().snapToBottom(squares);
                    break;
                case LEFT_ARROW: blocks.back().rotateCounterClock(squares);
                    break;
                case RIGHT_ARROW: blocks.back().rotateClock(squares);
                    break;
            }
        }

        g.getMouseLocation(mouse.x, mouse.y);
        blocks.back().strafeToMouse(mouse, squares);
        blocks.back().moveDown(squares);
        if (blocks.back().atBottom() || blocks.back().sitting(squares)) {
            blocks.back().remove(squares, g);
            blocks.back().draw(g);
            blocks.emplace_back();
            lineClear(squares, g);
            for (size_t i = 0; i < squares.size(); i++) {
                squares.at(i).draw(g);
            }
        }
        blocks.back().draw(g);

        g.update();
        g.Sleep(20);

    }

    return 0;
}

void lineClear(vector<Tile>& others, SDL_Plotter& g) {
    int lineCounts[16] = { 0 };
    int currentY = 1000;
    // Determining what lines are full
    for (int i = 0; i < others.size(); i++) {
        int currentY = others.at(i).getLoc().y;
        lineCounts[currentY / 50]++;
    }

    // Removing tiles in full lines
    for (int c = 15; c >= 0; c--) {
        if (lineCounts[c] == 12) {
            for (int i = 0; i < others.size(); i++) {
                currentY = others.at(i).getLoc().y;
                if (currentY == c * 50) {
                    others.at(i).remove(g);
                }
            }
            // Moving Everything else down
            for (int i = 0; i < others.size(); i++) {
                if (others.at(i).isDeleted() == false) {
                    others.at(i).moveDownLine(others);
                }
            }
            for (int i = 0; i < others.size(); i++) {
                if (others.at(i).isDeleted() == false) {
                    others.at(i).draw(g);
                }
            }
        }
    }

}
