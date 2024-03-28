#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
    int id;
    int num;
    int suit;
    string cardNum[13] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};
    int cardSuit[4] = {1, 2, 3, 4};
public:
    Card();

    void SetId(int);
    void PrintId();
    
    void SetNum(int);
    void PrintNum();

    void SetSuit(int);
    void PrintSuit();

    int* Shuffle();

    //void numTB(int);//Top & Bottom
    //void numSide(int);

    //void suit1(int, int);
    //void suit2(int, int);
    //void suit3(int, int);
    //void suit4(int, int);
    //void suit5(int, int);
    //void Deal(int);
};

class Deck{
public:
    Deck();
    Card card[52];

    void Shuffle();
    void Deal(int);
};

#endif