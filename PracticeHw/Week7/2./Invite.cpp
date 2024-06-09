#include "Invite.h"

Inviter::Inviter(){}

int Inviter::getFriendsSize(){
    return friends.size();
}

string Inviter::getFriend(int i){
    return friends[i];
}

void Inviter::addFriend(string friends){
    this->friends.push_back(friends);
}

void Inviter::display(){
    for(int i = 0; i < friends.size(); i++){
        cout << friends[i] << endl;
    }
}