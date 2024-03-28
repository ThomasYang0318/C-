#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
using namespace std;

class Player{
    int name;
    int money;
public:
    Player();
    void SetName();
    void PrintName();
    void SetMoney();
    void PrintMoney();
};

class BlackJ{

public:
    BlackJ();
    void ChooseBanker(int);
};

#endif