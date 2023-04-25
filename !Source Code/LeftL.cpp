#include "LeftL.h"

Block_LeftL::Block_LeftL() {
    loc = point((NUM_COL / 2) - (SIZE / 2), 3 * SIZE);
    block_color = BLUE;
    rotate = 1;

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

void Block_LeftL::setLoc(point inLoc) {
    prevLoc.push_back(getLoc());
    loc = inLoc;

    // Rotation 1
    if (rotate == 1) {
        a.setLoc(loc);
        b.setLoc(point(loc.x - SIZE, loc.y));
        c.setLoc(point(loc.x, loc.y - SIZE));
        d.setLoc(point(loc.x, loc.y - (2 * SIZE)));
    }
}

void Block_LeftL::setColor(color inColor) {
    block_color = inColor;
}

point Block_LeftL::getLoc() const {
    return loc;
}

color Block_LeftL::getColor() const {
    return block_color;
}

void Block_LeftL::draw(SDL_Plotter& g) {
    a.draw(g);
    b.draw(g);
    c.draw(g);
    d.draw(g);
    prevLoc.clear();
}

void Block_LeftL::moveDown(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    if (!atBottom() && !sitting(others)) {
        p.y++;
    }
    setLoc(p);
}

void Block_LeftL::snapToBottom(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    while (!atBottom() && !sitting(others)) {
        p.y++;
        setLoc(p);
    }
}

bool Block_LeftL::atBottom() {
    bool atBottom = false;
    if (rotate == 1) {
        if (getLoc().y >= NUM_ROW - SIZE) {
            atBottom = true;
        }
    }

    return atBottom;
}

bool Block_LeftL::sitting(vector<Tile>& others) {
    bool sit = false;
    point loc = getLoc();
    if (rotate == 1) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x == others.at(i).getLoc().x) {
                if (loc.y + SIZE == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
        }
    }

    return sit;
}
