/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/25/2023
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
    int rotation = 1;
    bool isDelete = false;

    public:
    // Specific Constructors
    Block_LeftL();
    Block_LeftL(point inLoc, int inRot, color inColor);

    // Block-Universal Functions
    void setColor(color inColor);
    void setRotation(int inRot);

    point getLoc() const;
    color getColor() const;
    int getRotation() const;

    void draw(SDL_Plotter& g);

    void rotateClock(vector<Tile>& others);
    void rotateCounterClock(vector<Tile>& others);

    void moveDown(vector<Tile>& others);
    void snapToBottom(vector<Tile>& others);

    int snapLateral(int in, int min, int max, int interval);

    // LeftL-Specific Functions
    void setLoc(point inLoc);

    void strafeToMouse(point mouseLoc, vector<Tile>& others);

    bool atBottom();
    bool sitting(vector<Tile>& others);
    void touchingTileSides(vector<Tile>& others, bool& touchingLeft, bool& touchingRight);

    void remove(vector<Tile>& others, SDL_Plotter& g); // Removes the Tiles from this object's "supervision"

};

#endif // LEFTL_H_INCLUDED
