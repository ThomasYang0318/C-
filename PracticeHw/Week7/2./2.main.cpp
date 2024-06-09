#include <iostream>
#include "Invite.h"
using namespace std;

int main(){
    Inviter Vincent;
    Inviter Leo;
    Inviter Invitee;
    
    
    cout << "Vincen's friend:" << endl;
    while(1){
        string name;
        cin >> name;
        if(name == "0"){
            break;
        }
        Vincent.addFriend(name);
    }
    cout << "Leo's friend:" << endl;
    while(1){
        string name;
        cin >> name;
        if(name == "0"){
            break;
        }
        Leo.addFriend(name);
    }
    
    string name;

    for(int i = 0; i < Vincent.getFriendsSize(); i++){
        name = Vincent.getFriend(i);
        Invitee.addFriend(name);
    }

    for(int i = 0; i < Leo.getFriendsSize(); i++){
        for(int j = 0; j < Vincent.getFriendsSize(); j++){
            if(Leo.getFriend(i) == Vincent.getFriend(j)){
                break;
            }
            if(j == Vincent.getFriendsSize() - 1){
                name = Leo.getFriend(i);
                Invitee.addFriend(name);
            }
        }
    }

    cout << "Invitee :" << endl;
    Invitee.display();
}