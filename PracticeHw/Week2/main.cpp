#include <iostream>
#include "skin.h"

using namespace std;

int main(){
    int money = 0;
    int state;
    string character;
    string style;
    //char character[3];
    Skin skin1;
    Skin skin2;
    Skin skin3;
    Skin skin4;

    skin1.setSkin("X", "1a", 100, 1);
    skin2.setSkin("X", "1b", 200, 1);
    skin3.setSkin("Y", "2a", 300, 1);
    skin4.setSkin("Y", "2b", 400, 1);


    cout << "Enter your money:" << endl;
    cin >> money;
    
    while(state != 2){
        cout << "Enter 1 to shop, 2 to leave:" << endl;
        cin >> state;
        if(state == 1){
            cout << " - - - - - - - - - - - - - - - - -" << endl
                 << "now available:                    " << endl;
            cout << "Character1:" << endl;
            skin1.printSkin();
            skin2.printSkin();
            cout << endl;
            cout << "Character2:" << endl;
            skin3.printSkin();
            skin4.printSkin();
            cout << endl;
            cout << " - - - - - - - - - - - - - - - - -" << endl;

            cout << "Enter the character you want to choose:";
            cin  >> character;
            cout << "Enter the style you want to purchase:";
            cin  >> style;
            if(character == "X"){
                if(style == "1a"){
                    //skin1.getSkin(money);
                    money = skin1.getSkin(money);
                }
                else if(style == "1b"){
                    //skin2.getSkin(money);
                    money = skin2.getSkin(money);
                }
            }
            else if(character == "Y"){
                if(style == "2a"){
                    //skin3.getSkin(money);
                    money = skin3.getSkin(money);
                }
                else if(style == "2b"){ 
                    //skin4.getSkin(money);
                    money = skin4.getSkin(money);
                }
            }
        }
        else if(state == 2){
            cout << "Thanks for coming. Hope to see you again soon!" << endl
                 << "--------------------------------" << endl;
        }
    }


}