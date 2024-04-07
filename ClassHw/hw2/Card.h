#ifndef CARD_H
#define CARD_H

#define NUM_OF_CARD 52
//#include "BlackJack.h"
#include <string>
using namespace std;

class Card{
    int id;
    int num;
    int suit;
    bool state;//open or close
public:
    Card(int);

    int GetNum();
    int GetSuit();
    bool GetState();
    void Flop();    //change the state
    
    vector<string> PrintCard() const;
};

class Deck {
public:
    Deck();
    mutable vector<Card> deck;
    const vector<Card>& getCards() const;
    void Shuffle(Deck& deck);
    Card Deal() const;
};
#endif