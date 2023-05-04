#include "Text.h"
#include "SDL_Plotter.h"
#include "Constants.h"
#include <cassert>

Letter::Letter(string inPath, point inLoc, color inColor, int inSizeMult) {
    path = inPath;
    loc = inLoc;
    text_color = inColor;
    sizeMult = inSizeMult;
}

void Letter::setPath(string inPath) {
    path = inPath;
}

void Letter::setLoc(point inLoc) {
    loc = inLoc;
}

void Letter::setColor(color inColor) {
    text_color = inColor;
}

void Letter::setSizeMult(int inMult) {
    sizeMult = inMult;
}

string Letter::getPath() const {
    return path;
}

point Letter::getLoc() const {
    return loc;
}

color Letter::getColor() const {
    return text_color;
}

int Letter::getSizeMult() const {
    return sizeMult;
}

void Letter::drawPixel(int locX, int locY, SDL_Plotter& g) {
    for (int r = 0; r < sizeMult; r++) {
        for (int c = 0; c < sizeMult; c++) {
            g.plotPixel(point(locX + c, locY + r), text_color);
        }
    }
}

void Letter::draw(SDL_Plotter& g) {
    ifstream inFile;
    inFile.open(path);
    assert(inFile.is_open());

    int rows = 0;
    int cols = 0;
    inFile >> rows >> cols;

    string line;
    int cCount = 0;
    for (int r = 0; r < rows * sizeMult; r += sizeMult) {
        inFile >> line;
        for (size_t c = 0; c < line.size() * sizeMult; c += sizeMult) {
            if (line.at(c / sizeMult) == '1') {
                drawPixel(loc.x + c, loc.y + r, g);
            }
        }
    }
}

void Letter::erase(SDL_Plotter& g) {
    color temp = text_color;
    text_color = BACKGROUND;
    draw(g);
    text_color = temp;
}
