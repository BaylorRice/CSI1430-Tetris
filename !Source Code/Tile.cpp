/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/25/2023
*/

#include "Tile.h"

Tile::Tile() {
    size = SIZE;
    tile_color = YELLOW;
    loc = point((NUM_COL / 2) - (SIZE / 2), SIZE);
}

Tile::Tile(int inSize, color inColor = YELLOW, point inLoc = point(0,0)) {
    size = inSize;
    tile_color = inColor;
    loc = inLoc;
}

void Tile::setSize(int inSize) {
    size = inSize;
}

void Tile::setLoc(point inLoc) {
    prevLoc.push_back(getLoc());
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

bool Tile::isDeleted() const {
    return isDelete;
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
            if ( r == drawSize - 2 or c == drawSize - 2) {
                currentCol = BLACK;
            }
            if (r == drawSize - 3 or c == drawSize - 3) {
                currentCol = BLACK;
            }
            inPlot.plotPixel(drawLoc.x + c, drawLoc.y + r, currentCol);
        }
    }
    prevLoc.clear();
}

void Tile::moveDown(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    if (!atBottom() && !sitting(others)) {
        p.y++;
    }
    setLoc(p);
}

void Tile::moveDownLine(vector<Tile>& others) {
    for (int i = 0; i < SIZE; i++) {
        point p = getLoc();
        prevLoc.push_back(getLoc());
        p.y++;
        setLoc(p);
    }
}

void Tile::snapToBottom(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    while (!atBottom() && !sitting(others)) {
        p.y++;
        setLoc(p);
    }
}

//void Tile::moveRight() {
//    point p = getLoc();
//    prevLoc.push_back(getLoc());
//    if (p.x < NUM_COL - getSize()) {
//        p.x += getSize();
//    }
//    setLoc(p);
//}
//
//void Tile::moveLeft() {
//    point p = getLoc();
//    prevLoc.push_back(getLoc());
//    if (p.x > 0) {
//        p.x -= getSize();
//    }
//    setLoc(p);
//}

void Tile::strafeToMouse(point mouseLoc) {
    point p = getLoc();
    prevLoc.push_back(getLoc());
    if (mouseLoc.x >= 551) {
        p.x = 550;
    }
    else if (mouseLoc.x >= 501) {
        p.x = 500;
    }
    else if (mouseLoc.x >= 451) {
        p.x = 450;
    }
    else if (mouseLoc.x >= 401) {
        p.x = 400;
    }
    else if (mouseLoc.x >= 351) {
        p.x = 350;
    }
    else if (mouseLoc.x >= 301) {
        p.x = 300;
    }
    else if (mouseLoc.x >= 251) {
        p.x = 250;
    }
    else if (mouseLoc.x >= 201) {
        p.x = 200;
    }
    else if (mouseLoc.x >= 151) {
        p.x = 150;
    }
    else if (mouseLoc.x >= 101) {
        p.x = 100;
    }
    else if (mouseLoc.x >= 51) {
        p.x = 50;
    }
    else if (mouseLoc.x >= 1) {
        p.x = 0;
    }
    else {
        p.x = 0;
    }
    setLoc(p);
}

bool Tile::atBottom() const {
    bool atBottom = false;
    if (getLoc().y >= NUM_ROW - getSize()) {
        atBottom = true;
    }
    return atBottom;
}

bool Tile::sitting(vector<Tile>& others) const{
    bool sit = false;
    point loc = getLoc();
    int size = getSize();
    for (int i = 0; i < others.size(); i++) {
        if (loc.x == others.at(i).getLoc().x) {
            if (loc.y + size == others.at(i).getLoc().y) {
                sit = true;
            }
        }
    }
    return sit;
}

void Tile::remove(SDL_Plotter& g) {
    point p(0, 900);
    setLoc(p);
    draw(g);
    isDelete = true;
}
