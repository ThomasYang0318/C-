#include "ShuffleAndDeal.h"
#include <iostream>
#include <string>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
using namespace std;

Card::Card(int size) {
    int deck[52];
    for(int i = 0; i < 52; i++){
        deck[i] = i;
    }
    
    random_device rd;
    mt19937 g(rd());
    shuffle(deck, deck + 51, g);
    
    for(int i = 0; i < size; i++){
        cards.push_back(deck[i]);
    }
};

void Card::Shuffle(){
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
    Print();
}

void Card::Deal(){
    if(cards.empty()){
        cout << "The deck is empty" << endl;
    }
    else{
        string suit[4] = {"Spade", "Heart", "Diamond", "Club"};
        string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        int s = cards.back() / 13;
        int n = cards.back() % 13;
        cout << "Your card:"<< suit[s] << " " << num[n] << endl;
        cards.pop_back();
    }
}

void Card::Print(){    
    string suit[4] = {"Spade", "Heart", "Diamond", "Club"};
    string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for(int i = 0; i < cards.size(); i++){
        int s = cards[i] / 13;
        int n = cards[i] % 13;
        cout << suit[s] << " " << num[n] << endl;
    }
}