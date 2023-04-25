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

void Block_LeftL::strafeToMouse(point mouseLoc) {
    point p = getLoc();
    prevLoc.push_back(p);
    if (rotation == 1) {
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
        else {
            p.x = 50;
        }
    }
    else if (rotation == 2) {
        if (mouseLoc.x >= 501) {
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
        else {
            p.x = 50;
        }
    }
    else if (rotation == 3) {
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
        else {
            p.x = 50;
        }
    }
    setLoc(p);
}

bool Block_LeftL::atBottom() {
    bool atBottom = false;
    if ((rotation == 1) || (rotation == 2)) {
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

    return sit;
}
