#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Box.h"

class Player{
    int PlayerX, PlayerY;
    int newPlayerX, newPlayerY;
    int initialPlayerX, initialPlayerY;
public:
    Player(Map& map);
    void move(Map&, int dx, int dy);
    void push(int dx, int dy);
    void PrintPlayer();
};

#endif