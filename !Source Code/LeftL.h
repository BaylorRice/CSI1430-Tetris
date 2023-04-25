/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/24/2023
*/

#include <iostream>
#include "Tile.h"
using namespace std;

#ifndef LEFTL_H_INCLUDED
#define LEFTL_H_INCLUDED

class Block_LeftL {
    private:
    point loc;
    vector<point> prevLoc;
    Tile a, b, c, d;
    color block_color;
    bool isDelete = false;

    public:
    Block_LeftL();
    Block_LeftL(point inLoc, color inColor);

    void rotateClock();
    void rotateCounterClock();

    void moveDown(vector<Tile>& others);

    void strafeToMouse(point mouseLoc);

    void atBottom();
    void sitting(vector<Tile>& others);

    void remove(vector<Tile>& others);
};

#endif // LEFTL_H_INCLUDED
