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
    Block_LeftL block;
    vector<Tile> squares(1);
    bool newSquare = true;
    int count = 0;
    //Block_leftL block;
    point mouse;

    while (!g.getQuit()) { // ESC

        if (g.kbhit()) {
            switch (toupper(g.getKey())) {
                case DOWN_ARROW: block.snapToBottom(squares);
                    break;
            }
        }
        block.moveDown(squares);
        block.draw(g);
        lineClear(squares, g);

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
