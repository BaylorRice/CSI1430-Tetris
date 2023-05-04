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

}