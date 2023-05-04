#include "Text.h"
#include "SDL_Plotter.h"
#include "Constants.h"
#include <cassert>

Letter::Letter(string inPath, point inLoc, color inColor) {
    path = inPath;
    loc = inLoc;
    text_color = inColor;
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

void Letter::draw(SDL_Plotter& g) {
    ifstream inFile;
    inFile.open(path);
    assert(inFile.is_open());

    int rows = 0;
    int cols = 0;
    inFile >> rows >> cols;

    string line;
    int cCount = 0;
    for (int r = 0; r < rows; r++) {
        inFile >> line;
        for (size_t c = 0; c < line.size(); c++) {
            if (line.at(c) == '1') {
                g.plotPixel(point(loc.y + c, loc.x + r), text_color);
            }
        }
    }

}