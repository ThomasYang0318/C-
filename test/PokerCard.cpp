#include "PokerCard.h"
#include <iostream>

PokerCard::PokerCard(std::string s, std::string r) : suit(s), rank(r) {}

void PokerCard::printCard() {
    std::cout << "┌───────┐" << std::endl;
    std::cout << "│ " << rank << "     │" << std::endl;
    std::cout << "│   " << suit << "   │" << std::endl;
    std::cout << "│     " << rank << " │" << std::endl;
    std::cout << "└───────┘" << std::endl;
}
