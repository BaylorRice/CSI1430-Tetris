/*
* Authors: 
* Assignment Title:
* Assignment Description:
* Due Date:
* Date Created:
* Date Last Modified:
*/

#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"

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