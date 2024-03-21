#include <iostream>
#include "skin.h"

using namespace std;

int main(){
    int money = 0;
    int state = 0;
    string character;
    string style;
    //char character[3];
    Skin skin1;
    Skin skin2;
    Skin skin3;
    Skin skin4;

    skin1.setSkin("Frieren", "1", 100, 1);
    skin2.setSkin("Frieren", "2", 200, 1);
    skin3.setSkin("Himmel", "3", 300, 1);
    skin4.setSkin("Himmel", "4", 400, 1);


    cout << "Enter your money:" << endl;
    cin >> money;
    
    while(state != 2){
        cout << "Enter 1 to shop, 2 to leave:" << endl;
        cin >> state;
        if(state == 1){
            cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl
                 << "now available:" << endl;
            cout << "Frieren:" << endl;
            skin1.printSkin();
            skin2.printSkin();
            cout << endl;
            cout << "Himmel:" << endl;
            skin3.printSkin();
            skin4.printSkin();
            cout << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;

            cout << "Enter the character you want to choose: ";
            cin  >> character;
            while(character != "Frieren" && character != "Himmel"){
                cout << "Sorry, there don't have this character." << endl;
                cout << "Enter the character you want to choose: ";
                cin  >> character;
            }
            cout << "Enter the style you want to purchase: ";
            cin  >> style;
            if(character == "Frieren"){
                while(style != "1" && style != "2"){
                cout << "Sorry, this character don't have this style." << endl;
                cout << "Enter the style you want to choose: ";
                cin  >> style;
                }
            }
            else if(character == "Himmel"){
                while(style != "3" && style != "4"){
                cout << "Sorry, this character don't have this style." << endl;
                cout << "Enter the style you want to choose: ";
                cin  >> style;
                }
            }

            if(character == "Frieren"){
                if(style == "1")
                    money = skin1.getSkin(money);
                else if(style == "2")
                    money = skin2.getSkin(money);
            }
            else if(character == "Himmel"){
                if(style == "3")
                    money = skin3.getSkin(money);
                else if(style == "4")
                    money = skin4.getSkin(money);
            }
        }
        else if(state == 2){
            cout << "Thanks for coming ~ Hope to see you again soon!" << endl
                 << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        }
        else{
            cout << "I don't know what you mean.";
            break;
        }
    }
}