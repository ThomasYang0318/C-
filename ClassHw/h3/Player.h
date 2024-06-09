#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Player{
    vector< vector<char> > map;
    int x, y;
public:
    Player();
    void GetMap(vector< vector<char> >& map);
    void ShowMap();
};
#endif