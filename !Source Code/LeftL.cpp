/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/25/2023
*/

#include "LeftL.h"

Block_LeftL::Block_LeftL() {
    loc = point((NUM_COL / 2) - (SIZE / 2), 3 * SIZE);
    block_color = BLUE;
    setColor(block_color);
    setLoc(loc);
}

Block_LeftL::Block_LeftL(point inLoc = point((NUM_COL / 2) - (SIZE / 2), 3 * SIZE), int inRot = 1, color inColor = BLUE) {
    loc = inLoc;
    rotation = inRot;
    block_color = inColor;
    setColor(block_color);
    setLoc(loc);
}

void Block_LeftL::setLoc(point inLoc) {
    prevLoc.push_back(getLoc());
    loc = inLoc;

    if (rotation == 1) {
        a.setLoc(loc);
        b.setLoc(point(loc.x - SIZE, loc.y));
        c.setLoc(point(loc.x, loc.y - SIZE));
        d.setLoc(point(loc.x, loc.y - (2 * SIZE)));
    }
    else if (rotation == 2) {
        a.setLoc(point(loc.x - SIZE, loc.y));
        b.setLoc(point(loc.x - SIZE, loc.y - SIZE));
        c.setLoc(loc);
        d.setLoc(point(loc.x + SIZE, loc.y));
    }
    else if (rotation == 3) {
        a.setLoc(point(loc.x - SIZE, loc.y - SIZE));
        b.setLoc(point(loc.x, loc.y - SIZE));
        c.setLoc(point(loc.x - SIZE, loc.y));
        d.setLoc(point(loc.x - SIZE, loc.y + SIZE));
    }
    else if (rotation == 4) {
        a.setLoc(point(loc.x, loc.y - SIZE));
        b.setLoc(loc);
        c.setLoc(point(loc.x - SIZE, loc.y - SIZE));
        d.setLoc(point(loc.x - (2 * SIZE), loc.y - SIZE));
    }

}

void Block_LeftL::setColor(color inColor) {
    block_color = inColor;
    a.setColor(block_color);
    b.setColor(block_color);
    c.setColor(block_color);
    d.setColor(block_color);
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

void Block_LeftL::rotateClock(vector<Tile>& others) {
    if (!atBottom() && !sitting(others)) {
        rotation++;
        if (rotation > 4) {
            rotation = 1;
        }
    }
}

void Block_LeftL::rotateCounterClock(vector<Tile>& others) {
    if (!atBottom() && !sitting(others)) {
        rotation--;
        if (rotation < 1) {
            rotation = 4;
        }
    }
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

int Block_LeftL::snapLateral(int in, int min, int max, int interval) {
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

void Block_LeftL::strafeToMouse(point mouseLoc, vector<Tile>& others) {
    point p = getLoc();
    prevLoc.push_back(p);
    if (!atBottom() && !sitting(others)) {
        // Check for Side to Side Collision
        if ((rotation == 1) || (rotation == 3)) {
            p.x = snapLateral(mouseLoc.x, SIZE, NUM_COL - SIZE, SIZE);
        }
        else if (rotation == 2) {
            p.x = snapLateral(mouseLoc.x, SIZE, NUM_COL - (2 * SIZE), SIZE);
        }
        else if (rotation == 4) {
            p.x = snapLateral(mouseLoc.x, (2 * SIZE), NUM_COL - SIZE, SIZE);
        }
    }
    setLoc(p);
}

bool Block_LeftL::atBottom() {
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

bool Block_LeftL::sitting(vector<Tile>& others) {
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

bool Block_LeftL::touchingTileSides(vector<Tile>& others) {
    bool isTouching = false;
    if (rotation == 1) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - SIZE == others.at(i).getLoc().x) {
                if (loc.y - (2 * SIZE) == others.at(i).getLoc().y) { // LEFT TOP
                    isTouching = true;
                }
                else if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT MIDDLE
                    isTouching = true;
                }
            }
            else if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // LEFT BOTTOM
                    isTouching = true;
                }
            }
            else if (loc.x + SIZE == others.at(i).getLoc().x) {
                if (loc.y - (2 * SIZE) == others.at(i).getLoc().y) { // RIGHT TOP
                    isTouching = true;
                }
                else if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT MIDDLE
                    isTouching = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    isTouching = true;
                }
            }
        }
    }
    else if (rotation == 2) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT TOP
                    isTouching = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // LEFT BOTTOM
                    isTouching = true;
                }
            }
            else if (loc.x == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT TOP
                    isTouching = true;
                }
            }
            else if (loc.x + (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    isTouching = true;
                }
            }
        }
    }
    else if (rotation == 3) {
        for (int i = 0; i < others.size(); i++) {
            if (loc.x - (2 * SIZE) == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // LEFT TOP
                    isTouching = true;
                }
                else if (loc.y == others.at(i).getLoc().y) { // LEFT MIDDLE
                    isTouching = true;
                }
                else if (loc.y + SIZE == others.at(i).getLoc().y) { // LEFT BOTTOM
                    isTouching = true;
                }
            }
            else if (loc.x + SIZE == others.at(i).getLoc().x) {
                if (loc.y - SIZE == others.at(i).getLoc().y) { // RIGHT TOP
                    isTouching = true;
                }
            }
            else if (loc.x == others.at(i).getLoc().x) {
                if (loc.y == others.at(i).getLoc().y) { // RIGHT MIDDLE
                    isTouching = true;
                }
                else if (loc.y + SIZE == others.at(i).getLoc().y) { // RIGHT BOTTOM
                    isTouching = true;
                }
            }
        }
    }
    return isTouching;
}

void Block_LeftL::remove(vector<Tile>& others, SDL_Plotter& g) {
    others.push_back(Tile(SIZE, YELLOW, a.getLoc()));
    others.push_back(Tile(SIZE, YELLOW, b.getLoc()));
    others.push_back(Tile(SIZE, YELLOW, c.getLoc()));
    others.push_back(Tile(SIZE, YELLOW, d.getLoc()));

    setLoc(point(0, 900));
    draw(g);
}
