#ifndef SHUFFLEANDDAEL_H
#define SHUFFLEANDDAEL_H
#include <vector>
#include <string>

using namespace std;

class Card{
private:
    vector<int> cards;
public:
    Card(int);

    void Shuffle();
    void Deal();
    void Print();
};

#endif