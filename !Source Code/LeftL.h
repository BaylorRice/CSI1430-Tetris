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
#include "SDL_Plotter.h"
using namespace std;

#ifndef LEFTL_H_INCLUDED
#define LEFTL_H_INCLUDED

class Block_LeftL {
    private:
    point loc;
    vector<point> prevLoc;
    Tile a, b, c, d;
    color block_color;
    int rotation = 2;
    bool isDelete = false;

    public:
    Block_LeftL();
    Block_LeftL(point inLoc, int inRot, color inColor);

    void setLoc(point inLoc);
    void setColor(color inColor);

    point getLoc() const;
    color getColor() const;

    void draw(SDL_Plotter& g);

    void rotateClock();
    void rotateCounterClock();

    void moveDown(vector<Tile>& others);
    void snapToBottom(vector<Tile>& others);

    // All below this line are ROTATIONALY DEPENDENT --------------------------------------------------------------------------------
    void strafeToMouse(point mouseLoc);

    bool atBottom();
    bool sitting(vector<Tile>& others);

    void remove(vector<Tile>& others); // Removes the Tiles from this object's "supervision"
};

#endif // LEFTL_H_INCLUDED
