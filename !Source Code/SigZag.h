/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: 04/27/2023
* Date Last Modified: 04/27/2023
*/

#include <iostream>
#include "Tile.h"
#include "SDL_Plotter.h"
using namespace std;

<<<<<<<< HEAD:!Source Code/SigZag.h
#ifndef SIGZAG_H_INCLUDED
#define SIGZAG_H_INCLUDED

class Block_SigZag {
========
#ifndef RIGHTL_H_INCLUDED
#define RIGHTL_H_INCLUDED

class Block_RightL {
>>>>>>>> 7149dc6337986b4aa0a0022c706815e6808f531a:!Source Code/RightL.h
    private:
    point loc;
    vector<point> prevLoc;
    Tile a, b, c, d;
    color block_color;
    int rotation = 1;
    bool isDelete = false;

    public:
    // Specific Constructors
<<<<<<<< HEAD:!Source Code/SigZag.h
    //CHANGE
    Block_SigZag();
    Block_SigZag(point inLoc, int inRot, color inColor);
//
========
    Block_RightL();
    Block_RightL(point inLoc, int inRot, color inColor);

>>>>>>>> 7149dc6337986b4aa0a0022c706815e6808f531a:!Source Code/RightL.h
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

    // LeftL-Specific Functions
    void setLoc(point inLoc);

    void strafeToMouse(point mouseLoc, vector<Tile>& others);

    bool atBottom();
    bool sitting(vector<Tile>& others);
    void touchingTileSides(vector<Tile>& others, bool& touchingLeft, bool& touchingRight);

    void remove(vector<Tile>& others, SDL_Plotter& g); // Removes the Tiles from this object's "supervision"

};

<<<<<<<< HEAD:!Source Code/SigZag.h
#endif // SIGZAG_H_INCLUDED
========
#endif // RIGHTL_H_INCLUDED
>>>>>>>> 7149dc6337986b4aa0a0022c706815e6808f531a:!Source Code/RightL.h
