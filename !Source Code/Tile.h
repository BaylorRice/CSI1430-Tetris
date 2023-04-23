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

    public:
    Tile();
    Tile(int, color, point);

    void setSize(int);
    void setLoc(point);
    void setColor(color);

    int getSize() const;
    point getLoc() const;
    color getColor() const;

    void draw(SDL_Plotter&);

    void moveDown();
    void moveRight();
    void moveLeft();

    void moveToMouse(point mouseLoc);
};

#endif TILE_H_