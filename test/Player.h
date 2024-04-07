#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
private:
    std::string name;
    int money;
    std::vector<Card> hand;
    int bet;

public:
    Player(std::string name, int money);
    void placeBet(int amount);
    void dealCard(Card card);
    void displayHand();
    int calculateHandValue();
    void clearHand();
    int getMoney();
    std::string getName();
};

#endif