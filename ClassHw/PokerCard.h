#ifndef POKERCARD_H
#define POKERCARD_H

class PokerCard{
    int color, num;
public:
    PokerCard ();
    void Color(char);
    void Number(int);
    void Deal(int);
};

#endif