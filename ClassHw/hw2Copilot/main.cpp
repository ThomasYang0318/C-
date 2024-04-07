#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Card {
public:
    int value;
    string suit;
    // Constructor
    Card(int v, string s) : value(v), suit(s) {}
};

class Player {
public:
    vector<Card> hand;
    int money;
    // Constructor
    Player(int m) : money(m) {}
    // Other methods
    void addCard(Card c) {
        hand.push_back(c);
    }
    int calculateScore() {
        // Calculate the score of the hand
    }
};

class Game {
public:
    vector<Player> players;
    vector<Card> deck;
    // Constructor
    Game(int numPlayers) {
        // Initialize players and deck
    }
    // Other methods
    void shuffleDeck() {
        // Shuffle the deck
    }
    void dealCards() {
        // Deal cards to players
    }
    void playerTurn(Player& p) {
        // Handle a player's turn
    }
    void dealerTurn() {
        // Handle the dealer's turn
    }
    void playRound() {
        // Play a round of the game
    }
};

int main() {
    // Create game
    Game game(2); // 2 players for example
    // Play game
    game.playRound();
    return 0;
}