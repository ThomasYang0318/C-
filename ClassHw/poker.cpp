#include "PokerCard.h"
#include <iostream>
#include <string>
using namespace std;

PokerCard::PokerCard(){};

void PokerCard::SuitUD(int suit){
    if(suit == 1){
        cout << "♣ ♣ ♣ ♣ ♣";
    }
    else if(suit == 2){
        cout << "♦ ♦ ♦ ♦ ♦";
    }
    else if(suit == 3){
        cout << "♥ ♥ ♥ ♥ ♥";
    }
    else if(suit == 4){
        cout << "♠ ♠ ♠ ♠ ♠";   
    }
};

void PokerCard::SuitSide(int suit){
    if(suit == 1){
        cout << "♣       ♣";
    }
    else if(suit == 2){
        cout << "♦       ♦";
    }
    else if(suit == 3){
        cout << "♥       ♥";
    }
    else if(suit == 4){
        cout << "♠       ♠";   
    }
};
void PokerCard::SuitMidL(int suit){
    if(suit == 1){
        cout << "♣";
    }
    else if(suit == 2){
        cout << "♦";
    }
    else if(suit == 3){
        cout << "♥";
    }
    else if(suit == 4){
        cout << "♠";   
    }
};
void PokerCard::SuitMidR(int suit){
    if(suit == 1){
        cout << "♣  ♣";
    }
    else if(suit == 2){
        cout << "♦  ♦";
    }
    else if(suit == 3){
        cout << "♥  ♥";
    }
    else if(suit == 4){
        cout << "♠  ♠";   
    }
};

void PokerCard::Number(int a){
    string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    if(a != 9)
        cout << "  " << num[a] << " ";
    else
        cout << " " << num[a] << " ";
};
/*
void PokerCard::Number(int num){
    for(int i = 0; i < 6; i++){
        cout << a <<
    }
};

void PokerCard::Deal(){

};
*/


/*
void PokerCard::Color(char color){
    if(color == 'club'){
        cout <<"       ***       "<< endl
             <<"      *****      "<< endl
             <<"        *        "<< endl
             <<"       ***      "<< endl;
    }
    else if(color == 'diamond'){
        cout <<"        *        "<< endl
             <<"       ***       "<< endl
             <<"      *****      "<< endl
             <<"     *******     "<< endl
             <<"     *******     "<< endl
             <<"      *****      "<< endl
             <<"       ***       "<< endl
             <<"        *        "<< endl;
    }
    else if(color == 'heart'){
        cout <<"   ***     ***   "<< endl
             <<"  *****   *****  "<< endl
             <<" ******* ******* "<< endl
             <<"  *************  "<< endl
             <<"   ***********   "<< endl
             <<"     *******     "<< endl
             <<"       ***       "<< endl
             <<"        *        "<< endl;
    }
    else if(color == 'spade'){
        cout <<"        *        "<< endl
             <<"       ***       "<< endl
             <<"      *****      "<< endl
             <<"    *********    "<< endl
             <<"   ***********   "<< endl
             <<"    *********    "<< endl
             <<"        *        "<< endl
             <<"       ***       "<< endl;
             
    }
};
*/