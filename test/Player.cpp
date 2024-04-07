#include "Player.h"

Player::Player(std::string name, int money) : name(name), money(money), bet(0) {}

void Player::placeBet(int amount) {
    if (amount <= money) {
        bet = amount;
        money -= bet;
    } else {
        std::cout << "Not enough money to place bet!" << std::endl;
    }
}

void Player::dealCard(Card card) {
    hand.push_back(card);
}

void Player::displayHand() {
    std::cout << name << "'s hand:" << std::endl;
    for (Card card : hand) {
        card.display();
    }
}

int Player::calculateHandValue() {
    int total = 0;
    for (Card card : hand) {
        total += card.getValue();
    }
    return total;
}

void Player::clearHand() {
    hand.clear();
}

int Player::getMoney() {
    return money;
}

std::string Player::getName() {
    return name;
}