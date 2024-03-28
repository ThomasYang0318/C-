#include "Card.h"
#include <iostream>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine

using namespace std;

Card::Card(){}

void Card::SetId(int i){
    id = i + 1;
}

void Card::PrintId(){
    cout << "Id: " << id << " ";
}

void Card::SetNum(int n){
    num = n % 13;
}

void Card::PrintNum(){
    cout << "Num: " << cardNum[num] << " ";
}

void Card::SetSuit(int n){
    suit = n / 13;
}

void Card::PrintSuit(){
    cout << "Suit: " << cardSuit[suit] << " ";
}

Deck::Deck(){}

void Deck::Shuffle(){
    random_device rd;
    mt19937 g(rd());
    shuffle(card, card + 52, g);
}

void Deck::Deal(int p){
    static int remain = 51;
    for(int i = 1; i <= p && remain >= 0; i++){
        cout << "Player" << i << ":"<< endl;
        card[remain].PrintNum();
        card[remain].PrintSuit();
        card[remain].PrintId();
        cout << " remain: " << remain;
        remain--;
        cout << endl << "-----------------------------------"<< endl;
    }
}
