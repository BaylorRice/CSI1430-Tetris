/*
* Authors: Reese Ford, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 05/02/2023
*/

#include "Line.h"
#include <vector>

Block_Line::Block_Line() {
    loc = point(NUM_COL/2, 0);
    block_color = LIGHT_BLUE;
    setColor(block_color);
    setLoc(loc);
}

Block_Line::Block_Line(point inLoc, int inRot = 1, color inColor = LIGHT_BLUE) {
    loc = inLoc;
    rotation = inRot;
    block_color = inColor;
    setColor(block_color);
    setLoc(loc);
}

void Block_Line::setLoc(point inLoc) {
    prevLoc.push_back(getLoc());
    loc = inLoc;

    if (rotation == 1) {
        a.setLoc(point(loc.x + SIZE, loc.y));
        b.setLoc(loc);
        c.setLoc(point(loc.x - SIZE, loc.y));
        d.setLoc(point(loc.x - (2 * SIZE), loc.y));
    }
    else if (rotation == 2) {
        a.setLoc(point(loc.x, loc.y - (2 * SIZE)));
        b.setLoc(point(loc.x, loc.y - SIZE));
        c.setLoc(loc);
        d.setLoc(point(loc.x, loc.y + SIZE));
    }

}

void Block_Line::setColor(color inColor) {
    block_color = inColor;
    a.setColor(block_color);
    b.setColor(block_color);
    c.setColor(block_color);
    d.setColor(block_color);
}

point Block_Line::getLoc() const {
    return loc;
}

color Block_Line::getColor() const {
    return block_color;
}

void Block_Line::draw(SDL_Plotter& g) {

    a.draw(g);
    b.draw(g);
    c.draw(g);
    d.draw(g);

    prevLoc.clear();
}

void Block_Line::rotateClock(vector<Tile>& others) {
    bool touchingLeft = false;
    bool touchingRight = false;
    touchingTileSides(others, touchingLeft, touchingRight);
    if (!atBottom() && !sitting(others) && !touchingLeft && !touchingRight) {
        if (rotation == 1) {
            rotation = 2;
        }
        else {
            rotation = 1;
        }
    }
}

void Block_Line::rotateCounterClock(vector<Tile>& others) {
    bool touchingLeft = false;
    bool touchingRight = false;
    touchingTileSides(others, touchingLeft, touchingRight);
    if (!atBottom() && !sitting(others) && !touchingLeft && !touchingRight) {
        if (rotation == 2) {
            rotation = 1;
        }
        else {
            rotation = 2;
        }
    }
}

void Block_Line::moveDown(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    if (!atBottom() && !sitting(others)) {
        p.y += SIZE;
    }
    setLoc(p);
}

void Block_Line::snapToBottom(vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    while (!atBottom() && !sitting(others)) {
        p.y++;
        setLoc(p);
    }
}

int Block_Line::snapLateral(int in, int min, int max, int interval) {
    int numIntervals = round((max - min) / interval);
    int snappedValue = round((in - min) / interval) * interval + min;

    if (snappedValue < min) {
        snappedValue = min;
    }
    else if (snappedValue > max) {
        snappedValue = max;
    }
    return snappedValue;
}

void Block_Line::strafeToMouse(point mouseLoc, vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    bool touchingLeft = false;
    bool touchingRight = false;
    touchingTileSides(others, touchingLeft, touchingRight);
    if (!touchingLeft && !touchingRight) {
        // MOVE FREELY
        if (rotation == 1) {
            p.x = snapLateral(mouseLoc.x, (2 * SIZE), NUM_COL - (2 * SIZE), SIZE);
        }
        else if (rotation == 2) {
            p.x = snapLateral(mouseLoc.x, 0, NUM_COL - SIZE, SIZE);
        }
    }
    else if (touchingLeft && !touchingRight) {
        // MOVE RIGHT ONLY
        if (rotation == 1) {
            p.x = snapLateral(mouseLoc.x, loc.x, NUM_COL - (2 * SIZE), SIZE);
        }
        else if (rotation == 2) {
            p.x = snapLateral(mouseLoc.x, loc.x, NUM_COL - SIZE, SIZE);
        }
    }
    else {
        // MOVE LEFT ONLY
        if (rotation == 1) {
            p.x = snapLateral(mouseLoc.x, (2 * SIZE), loc.x, SIZE);
        }
        else if (rotation == 2) {
            p.x = snapLateral(mouseLoc.x, 0, loc.x, SIZE);
        }
    }
    setLoc(p);
}

bool Block_Line::atBottom() {
    bool atBottom = false;
    if (rotation != 3) {
        if (getLoc().y >= NUM_ROW - SIZE) {
            atBottom = true;
        }
    }
    else if (rotation == 3) {
        if (getLoc().y >= NUM_ROW - (2 * SIZE)) {
            atBottom = true;
        }
    }

    return atBottom;
}

bool Block_Line::sitting(vector<Tile>& others) {
    bool sit = false;
    point loc = getLoc();
    if (rotation == 1) {
        for (int i = 0; i < others.size(); i++) {
            if ((loc.x == others.at(i).getLoc().x) || ((loc.x - SIZE) == others.at(i).getLoc().x)) {
                if (loc.y + SIZE == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
        }
    }
    else if (rotation == 2) {
        for (int i = 0; i < others.size(); i++) {
            if ((loc.x == others.at(i).getLoc().x) || 
                ((loc.x - SIZE) == others.at(i).getLoc().x) || 
                ((loc.x + SIZE) == others.at(i).getLoc().x)) {
                if (loc.y + SIZE == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
        }
    }
    else if (rotation == 3) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - SIZE == others.at(i).getLoc().x) {
                if (loc.y + (2 * SIZE) == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
            if (loc.x == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
        }
    }
    else if (rotation == 4) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x == others.at(i).getLoc().x) {
                if (loc.y + SIZE == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
            if (loc.x - SIZE == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
            if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) {
                    sit = true;
                }
            }
        }
    }

    return sit;
}

void Block_Line::touchingTileSides(vector<Tile>& others, bool& touchingLeft, bool& touchingRight) {
    touchingLeft = false;
    touchingRight = false;
    if (rotation == 1) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - SIZE == others.at(i).getLoc().x) {
                if (loc.y - (2 * SIZE) == others.at(i).getLoc().y) { // LEFT TOP
                    touchingLeft = true;
                }
                else if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT MIDDLE
                    touchingLeft = true;
                }
            }
            else if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // LEFT BOTTOM
                    touchingLeft = true;
                }
            }
            else if (loc.x + SIZE == others.at(i).getLoc().x) {
                if (loc.y - (2 * SIZE) == others.at(i).getLoc().y) { // RIGHT TOP
                    touchingRight = true;
                }
                else if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT MIDDLE
                    touchingRight = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    touchingRight = true;
                }
            }
        }
    }
    else if (rotation == 2) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT TOP
                    touchingLeft = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // LEFT BOTTOM
                    touchingLeft = true;
                }
            }
            else if (loc.x == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT TOP
                    touchingRight = true;
                }
            }
            else if (loc.x + (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    touchingRight = true;
                }
            }
        }
    }
    else if (rotation == 3) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT TOP
                    touchingLeft = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // LEFT MIDDLE
                    touchingLeft = true;
                }
                else if (loc.y + SIZE == others.at(i).getLoc().y) { // LEFT BOTTOM
                    touchingLeft = true;
                }
            }
            else if (loc.x + SIZE == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT TOP
                    touchingRight = true;
                }
            }
            else if (loc.x == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // RIGHT MIDDLE
                    touchingRight = true;
                }
                else if (loc.y + SIZE == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    touchingRight = true;
                }
            }
        }
    }
    else if (rotation == 4) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - (3 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT TOP
                    touchingLeft = true;
                }
            }
            else if (loc.x - SIZE == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // LEFT BOTTOM
                    touchingLeft = true;
                }
            }
            else if (loc.x + SIZE == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT TOP
                    touchingRight = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    touchingRight = true;
                }
            }
        }
    }
}

void Block_Line::remove(vector<Tile>& others, SDL_Plotter& g) {
    others.push_back(Tile(SIZE, block_color, a.getLoc()));
    others.push_back(Tile(SIZE, block_color, b.getLoc()));
    others.push_back(Tile(SIZE, block_color, c.getLoc()));
    others.push_back(Tile(SIZE, block_color, d.getLoc()));

    setLoc(point(0, (2*NUM_ROW)));
    draw(g);
}
