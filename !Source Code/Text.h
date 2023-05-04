/*
* Authors: Reese Ford, Blaine Daniels
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: 05/04/2023
* Date Last Modified: 05/04/2023
*/

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <iomanip>
#include <string>
#include <fstream>
#include "Constants.h"

using namespace std;

class Letter {
    private:
    string path = "0.txt";
    point loc = point(0,0);
    color text_color = BLACK;
    int sizeMult = 1;

    public:
    Letter() { ; }
    Letter(string inPath, point inLoc, color inColor);

    void setPath(string inPath);
    void setLoc(point inLoc);
    void setColor(color inColor);
    void setSizeMult(int inMult);

    string getPath() const;
    point getLoc() const;
    color getColor() const;
    int getSizeMult() const;

    void draw(SDL_Plotter& g);
    void erase(SDL_Plotter& g);

};

#endif // TEXT_H_INCLUDED