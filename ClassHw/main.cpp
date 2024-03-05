#include "PokerCard.h"
#include <iostream>

using namespace std;

int main(){
    char color[10];
    cout << "Choose a color: ";
    cin >> color;
    
    PokerCard poker(char color[]);
    
    poker.color();
}