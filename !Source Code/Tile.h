/*
* Authors: Reese Ford, Josie D'Acquisto, Blaine Daniels, MJ Ruhman,
    Omar Darwish, Benjamin Richter
* Assignment Title: Group Project - Tetris
* Assignment Description: Tetris recreated with the SDL Plotter
* Due Date: 05/04/2023
* Date Created: 04/20/2023
* Date Last Modified: 04/25/2023
*/

#ifndef TILE_H_
#define TILE_H_

#include "SDL_Plotter.h"
#include "Constants.h"

class Tile {
    private:
    int size;
    color tile_color;
    point loc;
    vector<point> prevLoc;
    bool isDelete = false;

    public:
    Tile();
    Tile(int, color, point); // int -> Size

    void setSize(int);
    void setLoc(point);
    void setColor(color);

    int getSize() const;
    point getLoc() const;
    color getColor() const;
    bool isDeleted() const;

    void draw(SDL_Plotter&);

    void moveDown(vector<Tile>& others);
    void moveDownLine(vector<Tile>& others);
    void snapToBottom(vector<Tile>& others);

    void strafeToMouse(point mouseLoc);

    bool atBottom() const;
    bool sitting(vector<Tile>& others) const;

    void remove(SDL_Plotter& g);

    /*void moveRight();
    void moveLeft();*/
};

#endif TILE_H_
