#include "BlackJack.h"
#include <iostream>

using namespace std;

Player::Player(){
    SetMoney();
}

void Player::SetMoney(){
    money = 10000;
}

void Player::PrintMoney(){
    cout << money;
}

BlackJ::BlackJ(){}

void BlackJ::ChooseBanker(int p){
    srand(time(NULL));
	cout << rand()%p + 1 << "莊家" << endl; //1~p
}