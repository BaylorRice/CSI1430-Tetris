#include "LeftL.h"

Block_LeftL::Block_LeftL() {
    loc = point((NUM_COL / 2) - (SIZE / 2), 3 * SIZE);
    block_color = BLUE;

    a.setColor(block_color);
    b.setColor(block_color);
    c.setColor(block_color);
    d.setColor(block_color);

    a.setLoc(loc);
    b.setLoc(point(loc.x - SIZE, loc.y));
    c.setLoc(point(loc.x, loc.y - SIZE));
    d.setLoc(point(loc.x, loc.y - (2 * SIZE)));

}

Block_LeftL::Block_LeftL(point inLoc, color inColor) {
    loc = inLoc;
    block_color = inColor;
}
