#include "Tile.h"

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

    prevLoc = getLoc();

    // Erase
    for (int r = 0; r < drawSize; r++) {
        for (int c = 0; c < drawSize; c++) {
            inPlot.plotPixel(prevLoc.x + c, prevLoc.y + r, BACKGROUND);
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
    prevLoc = getLoc();
}
