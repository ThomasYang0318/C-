#include "PokerCard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Set random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Define suits and ranks
    std::string suits[] = {"♥", "♦", "♣", "♠"};
    std::string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    // Ask for the specified suit from the assistant
    std::string targetSuit;
    std::cout << "Choose a suit (♥, ♦, ♣, ♠): ";
    std::cin >> targetSuit;

    // Print 13 cards of the specified suit, 4 cards per row
    for (int i = 0; i < 13; i += 4) {
        for (int j = i; j < i + 4; ++j) {
            PokerCard card(targetSuit, ranks[j]);
            card.printCard();
        }
        std::cout << std::endl;  // Newline
    }

    return 0;
}

