/*
* Authors: Reese Ford, Josie D'Acquisto, Blaine Daniels, MJ Ruhman
* Assignment Title: Group Project - Tetris
* Assignment Description: Tetris recreated with the SDL Plotter
* Due Date: 05/04/2023
* Date Created: 04/20/2023
* Date Last Modified: 05/04/2023
*/

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "SDL_Plotter.h"

const int NUM_ROW = 900; // Multiple of SIZE
const int NUM_COL = 600; // Multiple of SIZE

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
const color GREEN = color(6,143,6);

/* Scoring Guide:
* Block moves down a SIZE: 1pt
* Block Snapped: Additional 1pt
* Line Cleared: 100pt
* Tetris (4 Lines Cleared): 800pt
* Subsequent Tetris: 1200pt (reset after less than a tetris line clear)
*/

#endif // CONSTANT_H_
