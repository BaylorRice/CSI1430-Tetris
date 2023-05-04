/*
* Authors: Reese Ford, ...
* Assignment Title: Group Project - Tetris
* Assignment Description: INSERT DESCRIPTION
* Due Date: INSERT DUE DATE
* Date Created: 05/03/2023
* Date Last Modified: 05/03/2023
*/

#ifndef STARTSCREEN_H_INCLUDED
#define STARTSCREEN_H_INCLUDED

#include <iostream>

void drawStart(SDL_Plotter& g) {
    Block_RightL B1, B3, C1, S1;
    Block_Tee B2, K1;
    Block_LeftL L1, O1, O3, C2, S2;
    Block_Line O2;
    Tile tiles[13];

    // Set Block Rotations
    B1.setRotation(2);
    B2.setRotation(4);
    B3.setRotation(1);

    L1.setRotation(2);

    O1.setRotation(4);
    O2.setRotation(2);
    O3.setRotation(1);

    C1.setRotation(2);
    C2.setRotation(2);

    K1.setRotation(2);

    S1.setRotation(2);
    S2.setRotation(4);

    // Set Block Locations
    B1.setLoc(point(60, 60));
    B2.setLoc(point(90, 120));
    B3.setLoc(point(60, 150));

    L1.setLoc(point(180, 150));
    
    O1.setLoc(point(330, 60));
    O2.setLoc(point(270, 120));
    O3.setLoc(point(330, 150));

    C1.setLoc(point(270, 240));
    C2.setLoc(point(270, 330));

    K1.setLoc(point(390, 300));

    S1.setLoc(point(510, 240));
    S2.setLoc(point(540, 300));

    // Draw Everything
    for (int i = 0; i < 2; i++) {
        B1.draw(g);
        B2.draw(g);
        B3.draw(g);
        L1.draw(g);
        O1.draw(g);
        O2.draw(g);
        O3.draw(g);
        C1.draw(g);
        C2.draw(g);
        K1.draw(g);
        S1.draw(g);
        S2.draw(g);
    }


    g.update();

}

#endif //STARTSCREEN_H_INCLUDED
