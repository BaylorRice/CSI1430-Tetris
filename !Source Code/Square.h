/*
<<<<<<<< HEAD:!Source Code/Square.h
* Authors: Reese Ford, MJ Ruhman
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: 04/26/2023
* Date Last Modified: 05/02/2023
========
* Authors: Reese Ford, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/27/2023
>>>>>>>> 28327a4f98f912abac61093525738c7ee0f9205d:!Source Code/Line.h
*/

#include <iostream>
#include "Tile.h"
#include "SDL_Plotter.h"
using namespace std;

<<<<<<<< HEAD:!Source Code/Square.h
#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

class Block_Square {
========
#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

class Block_Line {
>>>>>>>> 28327a4f98f912abac61093525738c7ee0f9205d:!Source Code/Line.h
    private:
    point loc;
    vector<point> prevLoc;
    Tile a, b, c, d;
    color block_color;
    int rotation = 1;
    bool isDelete = false;

    public:
    // Specific Constructors
<<<<<<<< HEAD:!Source Code/Square.h
    Block_Square();
    Block_Square(point inLoc, int inRot, color inColor);
========
    Block_Line();
    Block_Line(point inLoc, int inRot, color inColor);
>>>>>>>> 28327a4f98f912abac61093525738c7ee0f9205d:!Source Code/Line.h

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

<<<<<<<< HEAD:!Source Code/Square.h
#endif // SQUARE_H_INCLUDED
========
#endif // LINE_H_INCLUDED
>>>>>>>> 28327a4f98f912abac61093525738c7ee0f9205d:!Source Code/Line.h
