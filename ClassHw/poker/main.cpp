#include "PokerCard.h"
#include <iostream>

using namespace std;

int main(){
    int suit;
    int RowNums;    //cards in one row

    cout << "Choose a suit (club: 1, diamond: 2, heart: 3, spade: 4): ";
    cin >> suit;
    while (suit != 1 && suit != 2 && suit != 3 && suit != 4){
        cout <<"Sorry, I don't know what suit you choose."<< endl
             <<"Please choose a suit again (club:1, diamond:2, heart:3, spade:4): ";
        cin >> suit;
    }

    cout << "How many cards do you want to print in a row (1 ~ 13): ";
    cin >> RowNums;
    while (RowNums < 1 || RowNums > 13){
        cout <<"Sorry, I don't know how many cards you want to print in a row."<< endl
             <<"Please tell me how many cards do you want to print in a row (1 ~ 13):  ";
        cin >> RowNums;
    }


    cout << "I will print all number in this suit (A,2,3,4,5,6,7,8,9,X,J,Q,K)" << endl << endl;

    PokerCard poker;

    for(int i = 0; i < 13 / RowNums; i++){
        for(int j = 0; j < RowNums; j++){
            poker.numTB(i * RowNums + j);
            cout << "  ";
            //cout << i * RowNums + j << " ";
        }

        cout << endl;

        for(int j = 0; j < RowNums; j++){
            poker.suit1(suit, i * RowNums + j);
            cout << "   ";
        }
        cout << endl;
        for(int j = 0; j < RowNums; j++){
            poker.suit2(suit, i * RowNums + j);
            cout << "   ";
        }
        cout << endl;
        for(int j = 0; j < RowNums; j++){
            poker.suit3(suit, i * RowNums + j);
            cout << "   ";
        }
        cout << endl;
        for(int j = 0; j < RowNums; j++){
            poker.suit4(suit, i * RowNums + j);
            cout << "   ";
        }
        cout << endl;
        for(int j = 0; j < RowNums; j++){
            poker.suit5(suit, i * RowNums + j);
            cout << "   ";
        }
        cout << endl;
        
        for(int j = 0; j < RowNums; j++){
            poker.numTB(i * RowNums + j);
            cout << "  ";
            //cout << i * RowNums + j << " ";
        }

        cout << endl << endl;
    }

    if(13 % RowNums != 0){
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.numTB(i);
            cout << "  ";
            //cout << i * RowNums + j << " ";
        }

        cout << endl;

        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.suit1(suit, i);
            cout << "   ";
        }
        cout << endl;
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.suit2(suit, i);
            cout << "   ";
        }
        cout << endl;
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.suit3(suit, i);
            cout << "   ";
        }
        cout << endl;
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.suit4(suit, i);
            cout << "   ";
        }
        cout << endl;
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.suit5(suit, i);
            cout << "   ";
        }
        cout << endl;
        
        for(int i = 13 - 13 % RowNums; i < 13; i++){
            poker.numTB(i);
            cout << "  ";
            //cout << i * RowNums + j << " ";
        }

        cout << endl << endl;
        //cout << i << " ";
    }
}
/*
cout << "suit: " << suit << endl;
cout << "RowNums: " << RowNums << endl;
*/