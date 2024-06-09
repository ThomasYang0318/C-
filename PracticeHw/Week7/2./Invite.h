#ifndef INVITE_H
#define INVITE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Inviter{
    vector<string> friends;
public:
    Inviter();

    int getFriendsSize();
    string getFriend(int);
    void addFriend(string friends);
    void display();
};

#endif