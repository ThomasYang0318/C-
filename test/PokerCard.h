#ifndef POKERCARD_H
#define POKERCARD_H

#include <string>

class PokerCard {
private:
    std::string suit;  // 花色
    std::string rank;  // 牌面大小

public:
    PokerCard(std::string s, std::string r);  // 建構函數
    void printCard();  // 印出撲克牌
};

#endif
