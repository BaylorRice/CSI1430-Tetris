/*
* Authors: Reese Ford, Josie D'Acquisto, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/27/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Constants.h"
#include "SDL_Plotter.h"

#include "Tile.h"
#include "LeftL.h"
#include "ZigZag.h"
#include "Line.h"

using namespace std;

void lineClear(vector<Tile>& others, SDL_Plotter& g);

int main(int argc, char** argv) {

    SDL_Plotter g(NUM_ROW, NUM_COL);

    //char key;
    vector<Block_Line> blocks(1);
    vector<Tile> squares(0);
    bool snapped = false;
    int timeCount = LEVELTIME/2;
    point mouse;
    bool gameOver = false;

    while (!g.getQuit() && !gameOver) { // ESC

        if (g.kbhit()) {
            switch (toupper(g.getKey())) {
                case DOWN_ARROW: blocks.back().snapToBottom(squares); snapped = true;
                    break;
                case LEFT_ARROW: blocks.back().rotateCounterClock(squares);
                    break;
                case RIGHT_ARROW: blocks.back().rotateClock(squares);
                    break;
            }
        }

        g.getMouseLocation(mouse.x, mouse.y);
        blocks.back().strafeToMouse(mouse, squares);

        if (timeCount == LEVELTIME/2) {
            blocks.back().moveDown(squares);
        }

        if ((timeCount == LEVELTIME) || snapped) {
            if (blocks.back().atBottom() || blocks.back().sitting(squares)) {
                blocks.back().remove(squares, g);
                blocks.emplace_back();
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
        blocks.back().draw(g);

        g.update();
        g.Sleep(REFRESH);
        timeCount += REFRESH;
        if (timeCount > LEVELTIME + 1) {
            timeCount = 0;
        }
        /*if (blocks.back().getLoc().y <= 0) {
            gameOver = true;
        }*/

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