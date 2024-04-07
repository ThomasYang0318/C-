#include "Card.h"
#include <cstdlib>
#include <ctime>

Card::Card(int value, std::string suit) : value(value), suit(suit) {}

int Card::getValue() {
    return value;
}

std::string Card::getSuit() {
    return suit;
}

void Card::display() {
    std::cout << value << " " << suit << std::endl;
}

Deck::Deck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (int value = 1; value <= 13; value++) {
        for (int i = 0; i < 4; i++) {
            cards.push_back(Card(value, suits[i]));
        }
    }
}


void Deck::shuffle() {
    srand(time(NULL));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}