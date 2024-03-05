#include "PokerCard.h"
#include <iostream>

using namespace std;

PokerCard::PokerCard(){

};

void PokerCard::Color(char color){
    if(color == 'club'){
        cout << "♣ ♣ ♣ ♣ ♣" << endl
             << "♣       ♣" << endl
             << "♣       ♣" << endl
             << "♣    ♣  ♣" << endl
             << "♣       ♣" << endl
             << "♣       ♣" << endl
             << "♣ ♣ ♣ ♣ ♣" << endl;
    }
    else if(color == 'diamond'){
        cout << "♦ ♦ ♦ ♦ ♦" << endl
             << "♦       ♦" << endl
             << "♦       ♦" << endl
             << "♦    ♦  ♦" << endl
             << "♦       ♦" << endl
             << "♦       ♦" << endl
             << "♦ ♦ ♦ ♦ ♦" << endl;
    }
    else if(color == 'heart'){
        cout << "♥ ♥ ♥ ♥ ♥" << endl
             << "♥       ♥" << endl
             << "♥       ♥" << endl
             << "♥    ♥  ♥" << endl
             << "♥       ♥" << endl
             << "♥       ♥" << endl
             << "♥ ♥ ♥ ♥ ♥" << endl;
    }
    else if(color == 'spade'){
        cout << "♠ ♠ ♠ ♠ ♠" << endl
             << "♠       ♠" << endl
             << "♠       ♠" << endl
             << "♠    ♠  ♠" << endl
             << "♠       ♠" << endl
             << "♠       ♠" << endl
             << "♠ ♠ ♠ ♠ ♠" << endl;   
    }
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