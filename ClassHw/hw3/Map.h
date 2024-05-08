#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Map{
public:
    Map();
    int rows, cols;
    vector<vector<char> > map;
    vector< vector<char> > OriginalMap ;
    void loadMapFromFile();
    void saveMapToFile();
    void printMap();
    void resetMap();
};

#endif