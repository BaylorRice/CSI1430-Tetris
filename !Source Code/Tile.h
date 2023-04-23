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