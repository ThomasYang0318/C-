#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"

class BlackJack {
private:
    Deck deck;
    std::vector<Player> players;
    int numPlayers;
    int currentPlayer;
    int dealerTotal;

public:
    BlackJack(int numPlayers);
    void play();
};

#endif