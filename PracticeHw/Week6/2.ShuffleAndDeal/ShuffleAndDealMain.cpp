#include "ShuffleAndDeal.h"
#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter 1 ~ 52 numbers , those numbers of cards are pushed into the deck :";
    cin >> num;
    while (num < 1 || num > 52) {
        cout << "Invalid input. Please enter a number from 1 to 52: ";
        cin >> num;
    }
    Card card(num);
    int state = 0;
    while(state != 3){
        cout << "-----------------------" << endl
             << "What do you want to do?" << endl
             << "1. deal one card" << endl
             << "2. shuffle" << endl
             << "3. exit" << endl;
        cin >> state;
        switch (state){
            case 1:
                card.Deal();
                break;
            case 2:
                card.Shuffle();
                break;
            case 3:
                cout << "Thanks for using.";
                break;
        }
    }
}