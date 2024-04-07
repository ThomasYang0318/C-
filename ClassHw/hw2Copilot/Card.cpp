#include <string>

using namespace std;

class Card {
public:
    int value;
    string suit;
    // Constructor
    Card(int v, string s) : value(v), suit(s) {}
};