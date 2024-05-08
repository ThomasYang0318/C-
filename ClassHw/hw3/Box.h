#ifndef BOX_H
#define BOX_H

#include "Map.h"

class Box{
    int BoxX, BoxY;
public:
    Box(Map& map);
    void Pushed(int dx, int dy);
    void PrintBox();
};

#endif