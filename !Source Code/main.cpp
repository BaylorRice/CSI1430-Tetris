/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/20/2023
*/

#include <iostream>
#include <cmath>
#include "SDL Files/SDL_Plotter.h"

using namespace std;

const int XSIZE = 500;
const int YSIZE = 500;

int main(int argc, char** argv) {

    SDL_Plotter g(XSIZE, YSIZE);
    while (!g.getQuit()) {

        // Code Here...

        g.update();
    }

    return 0;
}
