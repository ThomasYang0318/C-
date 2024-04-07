#include "BlackJack.h"

int main() {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    BlackJack game(numPlayers);
    game.play();

    return 0;
}