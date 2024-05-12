#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Destination{
    bool state;
    int x, y;
public:
    Destination();
    Destination(int, int);
    int GetX();
    int GetY();
    void ChangeObjectInside(int);
    bool ObjectInside();
    void Display();
};

#endif