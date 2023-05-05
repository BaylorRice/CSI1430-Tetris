/*
* Authors: Reese Ford, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: Tetris recreated with the SDL Plotter
* Due Date: 05/04/2023
* Date Created: 05/04/2023
* Date Last Modified: 05/04/2023
*/

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

Word::Word(point inLoc, int inSM, color inColor) {
    loc = inLoc;
    sizeMult = inSM;
    text_color = inColor;
}

void Word::setWord(string inString) {
    word = inString;
    letters.clear();
    for (size_t c = 0; c < inString.size(); c++) {
        char currentLetter = inString.at(c);
        string letterPath = "font/";
        if (currentLetter == ':') {
            letterPath += "COLON";
        }
        else if (currentLetter == ' ') {
            letterPath += "SPACE";
        }
        else {
            letterPath += currentLetter;
        }
        letterPath += ".txt";
        letters.push_back(Letter(letterPath, loc, text_color, sizeMult));
    }

    for (size_t i = 0; i < letters.size(); i++) {
        letters.at(i).setLoc(point(loc.x + (i * 12) * sizeMult, loc.y));
    }

}

void Word::setLoc(point inLoc) {
    loc = inLoc;
    setWord(word);
}

void Word::setSizeMult(int inSM) {
    sizeMult = inSM;
    setWord(word);
}

void Word::setColor(color inColor) {
    text_color = inColor;
    setWord(word);
}

string Word::getWord() const {
    return word;
}

point Word::getLoc() const {
    return loc;
}

int Word::getSizeMult() const {
    return sizeMult;
}

color Word::getColor() const {
    return text_color;
}

void Word::draw(SDL_Plotter& g) {
    for (size_t i = 0; i < letters.size(); i++) {
        letters.at(i).draw(g);
    }
}

void Word::erase(SDL_Plotter& g) {
    for (size_t i = 0; i < letters.size(); i++) {
        letters.at(i).erase(g);
    }
}
