#include "BlackJack.h"
#include <iostream>
#include <limits>

BlackJack::BlackJack(int numPlayers) : numPlayers(numPlayers), currentPlayer(0), dealerTotal(0) {
    std::string playerName;
    for (int i = 0; i < numPlayers; i++) {
        std::cout << "Enter player " << i+1 << "'s name: ";
        std::cin >> playerName;
        players.push_back(Player(playerName, 10000));
    }
}

void BlackJack::play() {
    deck.shuffle();
    for (int i = 0; i < 2; i++) {
        for (Player& player : players) {
            player.dealCard(deck.dealCard());
        }
        dealerTotal += deck.dealCard().getValue();
    }

    for (Player& player : players) {
        player.displayHand();
        int option;
        std::cout << "Player " << player.getName() << "'s turn:" << std::endl;
        do {
            std::cout << "1. Hit" << std::endl;
            std::cout << "2. Stand" << std::endl;
            std::cin >> option;
            switch (option) {
                case 1:
                    player.dealCard(deck.dealCard());
                    player.displayHand();
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Invalid option! Please try again." << std::endl;
            }
        } while (option != 2 && player.calculateHandValue() <= 21);
    }
}
