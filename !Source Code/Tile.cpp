#include "Tile.h"

Tile::Tile(int inSize = 50, color inColor = YELLOW, point inLoc = point(0,0)) {
    size = inSize;
    tile_color = inColor;
    loc = inLoc;
}
