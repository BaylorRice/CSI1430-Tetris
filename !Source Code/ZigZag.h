/*
* Authors: Reese Ford, Josie D'Acquisto, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: 04/26/2023
* Date Last Modified: 04/27/2023
*/

#include <iostream>
#include "Tile.h"
#include "SDL_Plotter.h"
using namespace std;

#ifndef ZIGZAG_H_INCLUDED
#define ZIGZAG_H_INCLUDED

class Block_ZigZag {
    private:
    point loc;
    vector<point> prevLoc;
    Tile a, b, c, d;
    color block_color;
    int rotation = 1;
    bool isDelete = false;

    public:
    // Specific Constructors
    Block_ZigZag();
    Block_ZigZag(point inLoc, int inRot, color inColor);

    // Block-Universal Functions
    void setColor(color inColor);

    point getLoc() const;
    color getColor() const;

    void draw(SDL_Plotter& g);

    void rotateClock(vector<Tile>& others);
    void rotateCounterClock(vector<Tile>& others);

    void moveDown(vector<Tile>& others);
    void snapToBottom(vector<Tile>& others);

    int snapLateral(int in, int min, int max, int interval);

    // Block-Specific Functions
    void setLoc(point inLoc);

    void strafeToMouse(point mouseLoc, vector<Tile>& others);

    bool atBottom();
    bool sitting(vector<Tile>& others);
    void touchingTileSides(vector<Tile>& others, bool& touchingLeft, bool& touchingRight);

    void remove(vector<Tile>& others, SDL_Plotter& g); // Removes the Tiles from this object's "supervision"

};

#endif // ZIGZAG_H_INCLUDED
