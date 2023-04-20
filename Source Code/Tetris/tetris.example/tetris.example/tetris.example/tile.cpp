//
//  tile.cpp
//  tetris.example
//
//  Created by josietwirls on 3/30/23.
//

// do not include constant file
#include "tile.h"


tile::tile(){
    size = 50;
    loc = point(0,0);
    tile_color = YELLOW;
}

tile::tile(int s){
    size = s;
    loc = point(0,0);
    tile_color = YELLOW;
}

tile::tile(int s, color c){
    size = s;
    loc = point(0,0);
    tile_color = c;
}

void tile::setSize(int){
    size = s;
}

void tile::setLocation(point p){
    //prev_loc = loc;
    if(p.x >= and p.x < NUM_COL and p.y >= 0 and p.y < NUM_ROW - size) {
        loc = p;
    }
}

void tile::setColor(color c){
    tile_color = c;
}

int tile::getSize() const{
    return size;
}

point tile::getLocation() const{
    return loc;
}

color tile::getColor() const{
    return tile_color;
}

void tile::draw(SDL_Plotter& g)const{
    color curr_color;
    prev_loc = loc
    //erase
    for(int r  = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            g.plotPixel(prev_loc.x + c, prev_loc.y + r, BACKGROUND);
        }
    }
    //draw
    for(int r  = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            curr_color = tile_color;
            if(r == 0 or c == 0 r == size - 1 or c == size - 1){
                curr_color = BLK;
            }
            g.plotPixel(loc.x + c, loc.y + r, curr_color);
        }
    }
    prev_loc = loc;
}

void tile::move() {
    point p = getLocation();
    p.y++;
    setLocation(p);
}
void tile::moveRight(){
    point p = getLocation();
    p.x += size;
    setLocation(p);
}
void tile::moveLeft(){
    point p = getLocation();
    p.x -= size;
    setLocation(p);
}
