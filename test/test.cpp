#include <iostream>
using namespace std;
#include <string>
int main(){
    vector<string> card(9);
    string cardNum[13] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};
    card[0] = "-----------------";
    card[1] = "|" + cardNum[1] + "           |";
    card[2] = "|               |";
    card[3] = "|               |";
    card[4] = "|               |";
    card[5] = "|               |";
    card[6] = "|               |";
    card[7] = "|             "+ cardNum[1] + "|";
    card[8] = "-----------------";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 3;j++)
            cout << card[i] << " ";
        cout << endl;
    }
} 