#include "BlackJack.h"
#include "Card.h"
#include <iostream>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <vector>

using namespace std;

Card::Card(int cardId) : id(cardId), state(true){
    num = cardId % 13 + 1;  //1 ~ 13
    suit = cardId / 13 + 1; //1 ~ 4
}

int Card::GetNum(){
    return num;
}

int Card::GetSuit(){
    int cardSuit[4] = {1, 2, 3, 4};
    return cardSuit[suit];
}

bool Card::GetState(){
    return state;
}


void Card::Flop(){
    state = !state;
}

vector<string> Card::PrintCard() const{
    vector<string> card(9);
    if(state == 1){
        string cardNum[13] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};
        card[0] = "---------------";
        card[1] = "|" + cardNum[num - 1] + "           |";
        switch(suit){
        case 1:                     
            card[2] = "|     ***     |";
            card[3] = "|  ** *** **  |";
            card[4] = "|  **  *  **  |";
            card[5] = "|      *      |";
            card[6] = "|     ***     |";
            break;
        case 2:
            card[2] = "|      *      |";
            card[3] = "|     ***     |";
            card[4] = "|    *****    |";
            card[5] = "|     ***     |";
            card[6] = "|      *      |";
            break;
        case 3:
            card[2] = "|    *   *    |";
            card[3] = "|   *** ***   |";
            card[4] = "|    *****    |";
            card[5] = "|     ***     |";
            card[6] = "|      *      |";
            break;
        case 4:
            card[2] = "|      *      |";
            card[3] = "|    *****    |";
            card[4] = "|   *** ***   |";
            card[5] = "|      *      |";
            card[6] = "|     ***     |";
            break;
        }
        card[7] = "|           " + cardNum[num - 1] + "|";
        card[8] = "---------------";
    }
    else{
        card[0] = "---------------";
        card[1] = "|             |";
        card[2] = "|             |";
        card[3] = "|             |";
        card[4] = "|             |";
        card[5] = "|             |";
        card[6] = "|             |";
        card[7] = "|             |";
        card[8] = "---------------";
    }
    return card;
}


Deck::Deck(){
    // Initialize card IDs
    vector<int> cardID;
    for (int i = 0; i < NUM_OF_CARD; i++) {
        cardID.push_back(i);
    }

    // Create cards and add them to the deck
    for (int id : cardID) {
        deck.push_back(Card(id));
    }
    
}

const vector<Card>& Deck::getCards() const {
    return deck;
}

void Deck::Shuffle(Deck &d){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

Card Deck::Deal() const{
    Card dealCard = deck.back();
    deck.pop_back();
    return dealCard;
}
