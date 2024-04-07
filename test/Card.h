#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>

class Card {
private:
    int value;
    std::string suit;

public:
    Card(int value, std::string suit);
    int getValue();
    std::string getSuit();
    void display();
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card dealCard();
};

#endif
