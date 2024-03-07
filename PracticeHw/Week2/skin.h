#ifndef SKIN_H
#define SKIN_H

#include <string>

using namespace std;

class Skin{
public:
    Skin();
    void setSkin(string , string, int, bool);
    int getSkin(int);
    void printSkin();
    //void inStore;
private:
    string character;
    string style;
    int price;
    bool state;
};

#endif