#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    int x, y;
public:
    Player();
    Player(int, int);
    void Move(int ,int);
    int GetX();
    int GetY();
    void Display();
    //bool IsNeighbor();
};

#endif