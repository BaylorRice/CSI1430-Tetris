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
