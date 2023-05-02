/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: ...
* Date Last Modified: 04/27/2023
*/

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "SDL_Plotter.h"

const int NUM_ROW = 900; // Multiple of SIZE
const int NUM_COL = 600; // Multiple of SIZE

// Level 1: 400
const int LEVELTIME = 400; // Multiple of 10, leading digit being even

const int REFRESH = 10;

const int SIZE = 30; // Multiple of 10

const color YELLOW = color(220, 220, 20);
const color RED = color(220, 20, 20);
const color BLUE = color(10, 10, 220);
const color PURPLE = color(150, 23, 179);
const color LIGHT_BLUE = color(66, 135, 245);
const color ORANGE = color(255, 108, 19);
const color BLACK = color(0, 0, 0);
const color GREY = color(135, 135, 135);
const color BACKGROUND = color(255, 255, 255);

#endif // CONSTANT_H_
