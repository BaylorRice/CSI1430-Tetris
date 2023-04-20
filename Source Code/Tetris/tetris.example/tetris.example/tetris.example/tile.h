//
//  tile.h
//  tetris.example
//
//  Created by josietwirls on 3/30/23.
//

#ifndef tile_h
#define tile_h

#include "SDL_Plotter.h"
#include "constant.h"

class tile{
private:
    int   size;
    color tile_color;
    point loc, prev_loc;
    
public:
    tile();
    tile(int s);
    tile(int s, color c);
    
    void setSize(int);
    void setLocation(point);
    void setColor(color);
    
    int getSize() const;
    int getLocation() const;
    int getColor() const;
    
    void draw(SDL_Plotter& g)const;
    
    void move();
    void moveRight();
    void moveLeft();
    
    
}

#endif /* tile_h */
