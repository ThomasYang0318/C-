#include "skin.h"
#include <iostream>
#include <string>

using namespace std;

Skin::Skin(){
    setSkin(character, style, price, state);
};

void Skin::setSkin(string c, string s, int p, bool states){
    character = c;
    style = s;
    price = p;
    state = states;
};

int Skin::getSkin(int money){
    if(money < price)
        cout << "Sorry! You don't have enough money." << endl;
    else if(money >= price){
        money -= price ;
        cout << "Congratulation ! You have style " << "\"" << style << "\" now."<< endl;
        cout << "Your money: " << money << endl;
        state = 0;
    }
    return money;
};

void Skin::printSkin(){
    if(state == 1)
        cout << "  "<< style << ": " << price;
    else if(state == 0)
        cout << "  "<< style << ": sold out";
}
