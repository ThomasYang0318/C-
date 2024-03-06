#include "PokerCard.h"
#include <iostream>

using namespace std;

int main() {
    int suit;
    int CardNum;
    int a = 0;

    cout << "Choose a suit (♣:1, ♦:2, ♥:3, ♠:4): ";
    cin >> suit;
    while (suit != 1 && suit != 2 && suit != 3 && suit != 4){
        cout <<"Sorry, I don't know what you choose."<< endl
             <<"Please choose a suit again (♣:1, ♦:2, ♥:3, ♠:4): ";
        cin >> suit;
    }

    cout << "How many cards do you want to print in a row (1 ~ 13): ";
    cin >> CardNum;

    PokerCard poker;

    for (int i = 0; i < 13 && (13 - a) >= CardNum; i += CardNum) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || j == 6) {
                for (int k = 0; k < CardNum; k++) {
                    poker.SuitUD(suit);
                    cout << "  ";
                }
                cout << endl;
            } else if (j == 3) {
                for (int k = 0; k < CardNum; k++) {
                    poker.SuitMidL(suit);
                    poker.Number(a);
                    poker.SuitMidR(suit);
                    cout << "  ";
                    a++;
                }
                cout << endl;
            } else {
                for (int k = 0; k < CardNum; k++) {
                    poker.SuitSide(suit);
                    cout << "  ";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    if(13 % CardNum != 0 ){
        for (int i = 0; i < 7; i++) {
            if (i == 0 || i == 6) {
                for (int j = 0; j < 13 % CardNum; j++) {
                    poker.SuitUD(suit);
                    cout << "  ";
                }
                cout << endl;
            } 
            else if (i == 3) {
                for (int j = 0; j < 13 % CardNum; j++) {
                    poker.SuitMidL(suit);
                    poker.Number(a);
                    poker.SuitMidR(suit);
                    cout << "  ";
                    a++;
                }
                cout << endl;
            } 
            else {
                for (int j = 0; j < 13 % CardNum; j++) {
                    poker.SuitSide(suit);
                    cout << "  ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}