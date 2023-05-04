/*
* Authors: Reese Ford, Josie D'Acquisto, Blaine Daniels, MJ Ruhman
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 05/04/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Constants.h"
#include "SDL_Plotter.h"
#include "Text.h"

#include "Tile.h"
#include "LeftL.h"
#include "ZigZag.h"
#include "SigZag.h"
#include "Square.h"
#include "Tee.h"
#include "Line.h"
#include "RightL.h"

#include "startScreen.h"

using namespace std;

int lineClear(vector<Tile>& others, SDL_Plotter& g);
class Current_Block {
    private:
    Block_LeftL leftL; // Block 0
    Block_RightL rightL; // Block 1
    Block_Line line; // Block 2
    Block_Tee tee; // Block 3
    Block_Square square; // Block 4
    Block_ZigZag zigzag; // Block 5
    Block_SigZag sigzag; // Block 6
    int block = -1;

    public:
    Current_Block() {
        ;
    }

    void draw(SDL_Plotter& g) {
        if (block == 0) {
            leftL.draw(g);
        }
        else if (block == 1) {
            rightL.draw(g);
        }
        else if (block == 2) {
            line.draw(g);
        }
        else if (block == 3) {
            tee.draw(g);
        }
        else if (block == 4) {
            square.draw(g);
        }
        else if (block == 5) {
            zigzag.draw(g);
        }
        else if (block == 6) {
            sigzag.draw(g);
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
        else if (block == 4) {
            square.rotateClock(others);
        }
        else if (block == 5) {
            zigzag.rotateClock(others);
        }
        else if (block == 6) {
            sigzag.rotateClock(others);
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
        else if (block == 4) {
            square.rotateCounterClock(others);
        }
        else if (block == 5) {
            zigzag.rotateCounterClock(others);
        }
        else if (block == 6) {
            sigzag.rotateCounterClock(others);
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
        else if (block == 4) {
            square.moveDown(others);
        }
        else if (block == 5) {
            zigzag.moveDown(others);
        }
        else if (block == 6) {
            sigzag.moveDown(others);
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
        else if (block == 4) {
            square.snapToBottom(others);
        }
        else if (block == 5) {
            zigzag.snapToBottom(others);
        }
        else if (block == 6) {
            sigzag.snapToBottom(others);
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
        else if (block == 4) {
            square.strafeToMouse(mouseLoc, others);
        }
        else if (block == 5) {
            zigzag.strafeToMouse(mouseLoc, others);
        }
        else if (block == 6) {
            sigzag.strafeToMouse(mouseLoc, others);
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
        else if (block == 4) {
            atBot = square.atBottom();
        }
        else if (block == 5) {
            atBot = zigzag.atBottom();
        }
        else if (block == 6) {
            atBot = sigzag.atBottom();
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
        else if (block == 4) {
            sit = square.sitting(others);
        }
        else if (block == 5) {
            sit = zigzag.sitting(others);
        }
        else if (block == 6) {
            sit = sigzag.sitting(others);
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
        else if (block == 4) {
            square.remove(others, g);
        }
        else if (block == 5) {
            zigzag.remove(others, g);
        }
        else if (block == 6) {
            sigzag.remove(others, g);
        }
    }
    void moveOff() {
        if (block == 0) {
            leftL.setLoc(point(0, (2*NUM_ROW)));
        }
        else if (block == 1) {
            rightL.setLoc(point(0, (2*NUM_ROW)));
        }
        else if (block == 2) {
            line.setLoc(point(0, (2*NUM_ROW)));
        }
        else if (block == 3) {
            tee.setLoc(point(0, (2*NUM_ROW)));
        }
        else if (block == 4) {
            square.setLoc(point(0, (2 * NUM_ROW)));
        }
        else if (block == 5) {
            zigzag.setLoc(point(0, (2 * NUM_ROW)));
        }
        else if (block == 6) {
            sigzag.setLoc(point(0, (2 * NUM_ROW)));
        }
    }

    void newBlock(SDL_Plotter& g) {
        block = rand() % 5;
        leftL.setLoc(point(-100, 0));
        rightL.setLoc(point(-100, 0));
        line.setLoc(point(-100, 0));
        tee.setLoc(point(-100, 0));
        square.setLoc(point(-100, 0));
        zigzag.setLoc(point(-100, 0));
        sigzag.setLoc(point(-100, 0));
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
        else if (block == 4) {
            square.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        else if (block == 5) {
            zigzag.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        else if (block == 6) {
            sigzag.setLoc(point(NUM_COL / 2, 2 * SIZE));
        }
        leftL.draw(g);
        rightL.draw(g);
        line.draw(g);
        tee.draw(g);
        square.draw(g);
        zigzag.draw(g);
        sigzag.draw(g);
    }

};

int main(int argc, char** argv) {

    // The window of power (and extreme frustration)
    SDL_Plotter g(NUM_ROW, NUM_COL);

    // Start Screen
    bool startGame = false;
    drawStart(g);
    g.update();
    g.Sleep(20);

    // Text on Start Screen
    Word button1(point(208, 455), 4, BLACK);
    button1.setWord("SLOW");
    button1.draw(g);

    Word button2(point(200, 610), 3, BLACK);
    button2.setWord("NORMAL");
    button2.draw(g);

    Word button3(point(209, 755), 4, BLACK);
    button3.setWord("FAST");
    button3.draw(g);

    Word mouseText(point(30, 870), 1, BLACK);
    mouseText.setWord("USE MOUSE TO SELECT - PRESS ANY KEY TO PLAY");
    mouseText.draw(g);
    g.update();
    g.Sleep(20);


    point startMouse = point(0, 0);
    int levelTime = 400;
    bool gameStart = true;
    while (!g.getQuit() && !g.kbhit()) {    
        g.getMouseLocation(startMouse.x, startMouse.y);
        if (g.getQuit()) {
            gameStart = false;
        }
    }

    if ((startMouse.x >= 180) && (startMouse.x <= 420)) {
        if ((startMouse.y >= 420) && (startMouse.y <= 540)) {
            levelTime = 600;
        }
        else if ((startMouse.y >= 570) && (startMouse.y <= 690)) {
            levelTime = 400;
        }
        else if ((startMouse.y >= 720) && (startMouse.y <= 840)) {
            levelTime = 100;
        }
    }

    g.clear();
    g.update();
    g.Sleep(500);
    
    if (gameStart) {
        // Data Abstraction
        vector<Tile> squares(0);
        bool snapped = false;
        int numLinesCleared = 0;
        bool tetrisCombo = false;
        int score = 0;
        int timeCount = levelTime / 2;
        point mouse;
        bool gameOver = false;

        // Creates the Current_Block object and resets it (instead of a defualt constructor)
        Current_Block block;
        block.newBlock(g);

        // Game loop
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
            if (snapped) {
                score += 1;
            }
            if (timeCount == levelTime / 2) {
                block.moveDown(squares);
                score += 1;
            }

            if ((timeCount == levelTime) || snapped) {
                // If at the bottom or sitting on other Tiles
                if (block.atBottom() || block.sitting(squares)) {
                    // Dissociate the Tiles from the Current Block, place them in squares, and move the block below the screen
                    block.remove(squares, g);

                    // Clear any lines, apply scoring, and redraw the squares
                    numLinesCleared = lineClear(squares, g);
                    if (numLinesCleared == 0) {
                        tetrisCombo = false;
                    }
                    else if (numLinesCleared == 1) {
                        score += 100;
                        tetrisCombo = false;
                    }
                    else if (numLinesCleared == 4) {
                        if (tetrisCombo) {
                            score += 1200;
                        }
                        else {
                            score += 800;
                            tetrisCombo = true;
                        }
                    }
                    numLinesCleared = 0;
                    for (size_t i = 0; i < squares.size(); i++) {
                        squares.at(i).draw(g);
                    }
                    for (size_t i = 0; i < squares.size(); i++) {
                        squares.at(i).draw(g);
                    }

                    // "Regenerate" the current block
                    block.newBlock(g);
                    timeCount = levelTime / 2;
                }
                snapped = false;
            }

            // Check for Game Over
            for (size_t i = 0; i < squares.size(); i++) {
                if (squares.at(i).getLoc().y < (2 * SIZE)) {
                    gameOver = true;
                    block.moveOff();
                }
            }

            // Draw the block
            block.draw(g);

            // Update the screen and timeCount
            g.update();
            g.Sleep(REFRESH);
            timeCount += REFRESH;
            if (timeCount > levelTime + 1) {
                timeCount = 0;
            }

        }

        // Upon Game Over
        if (gameOver) {
            for (size_t i = 0; i < squares.size(); i++) {
                squares.at(i).setColor(RED);
                squares.at(i).draw(g);
            }
            g.update();
            cout << endl << "Game Over" << endl;

            // Wait for Plotter Quit to end program
            while (!g.getQuit()) { ; }
        }
    }
    return 0;
}

int lineClear(vector<Tile>& others, SDL_Plotter& g) {
    vector<int> lineCounts(NUM_ROW / SIZE, 0);
    int currentY = NUM_ROW;
    int numLinesCleared = 0;

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
            numLinesCleared++;
        }
    }
    //Fully delete removed tiles
    for (size_t i = 0; i < others.size(); i++) {
        if (others.at(i).isDeleted() == true) {
            others.erase(others.begin() + i);
            i--;
        }
    }

    return numLinesCleared;
}
