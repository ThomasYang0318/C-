#ifndef POKERCARD_H
#define POKERCARD_H
#include <string>

using namespace std;

class PokerCard{
    string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};
    //int suit[4] = {1, 2, 3, 4};
public:
    PokerCard();

    void numTB(int);//Top & Bottom
    //void numSide(int);

    void suit1(int, int);
    void suit2(int, int);
    void suit3(int, int);
    void suit4(int, int);
    void suit5(int, int);
    //void Deal(int);
};

#endif