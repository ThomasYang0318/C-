#ifndef POKERCARD_H
#define POKERCARD_H
//#include <string>

//using namespace std;

class PokerCard{
    //string color;
    int num;
public:
    PokerCard();

    void SuitUD(int); //Up & Down
    void SuitMidL(int);
    void SuitMidR(int);
    void SuitSide(int);

    void Number(int);
    //void Deal(int);
};

#endif