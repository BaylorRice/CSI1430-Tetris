#include "Tile.h"

Tile::Tile() {
    size = 50;
    tile_color = YELLOW;
    loc = point(0, 0);
}

Tile::Tile(int inSize = 50, color inColor = YELLOW, point inLoc = point(0,0)) {
    size = inSize;
    tile_color = inColor;
    loc = inLoc;
}

void Tile::setSize(int inSize) {
    size = inSize;
}

void Tile::setLoc(point inLoc) {
    loc = inLoc;
}

void Tile::setColor(color inColor) {
    tile_color = inColor;
}

int Tile::getSize() const {
    return size;
}

point Tile::getLoc() const {
    return loc;
}

color Tile::getColor() const {
    return tile_color;
}

void Tile::draw(SDL_Plotter& inPlot) {
    color currentCol;
    int drawSize = getSize();
    point drawLoc = getLoc();

    // Erase
    for (int i = 0; i < prevLoc.size(); i++) {
        for (int r = 0; r < drawSize; r++) {
            for (int c = 0; c < drawSize; c++) {
                inPlot.plotPixel(prevLoc.at(i).x + c, prevLoc.at(i).y + r, BACKGROUND);
            }
        }
    }
    
    // Draw
    for (int r = 0; r < drawSize; r++) {
        for (int c = 0; c < drawSize; c++) {
            currentCol = tile_color;
            if (r == 0 or c == 0 or r == drawSize - 1 or c == drawSize - 1) {
                currentCol = BLACK;
            }
            inPlot.plotPixel(drawLoc.x + c, drawLoc.y + r, currentCol);
        }
    }
    prevLoc.clear();
}

void Tile::moveDown() {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    if (p.y < NUM_ROW - getSize()) {
        p.y++;
    }
    setLoc(p);
}

void Tile::moveRight() {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    if (p.x < NUM_COL - getSize()) {
        p.x += getSize();
    }
    setLoc(p);
}

void Tile::moveLeft() {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    if (p.x > 0) {
        p.x -= getSize();
    }
    setLoc(p);
}

void Tile::moveToMouse(point mouseLoc) {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    if (mouseLoc.x < NUM_COL - getSize()) {
        p.x = mouseLoc.x;
    }
    else if (mouseLoc.x > NUM_COL - getSize()) {
        p.x = NUM_COL - getSize();
    }
    setLoc(p);
}
