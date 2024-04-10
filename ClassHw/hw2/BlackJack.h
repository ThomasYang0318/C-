#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"

#include <vector>
#include <limits>
#include <string>
using namespace std;

class Hand : public Card{
    bool bust;
public:
    Hand();
    vector<Card> cards;
    
    void AddCard(const Deck& deck);
    int GetCardNum(int);
    void ShowCard();

    int CalculateCard();
    void Bust();
    bool GetBust();

    void CleanCard();
};

class Player : public Hand{
    int name;
    int money;
    bool isBanker;
    int bet;
    vector<Hand> hand;
public:
    Player();

    void BeBanker();
    bool GetBanker();
    int GetName();
    int GetMoney();
    void ChangeMoney(int);
    void SetBet(int);
    int GetBet();
    int GetHandNum();
    void CleanHand();
    void SetAllCardsVisible();
    void Print();
    void BankerPrint();
    void EndPrint();
};


class Banker : private Player{
public:
    Banker();
};

class Game{

public:
    Game();
    void ChooseBanker(int, vector<Player>& player);
    bool Surrender(int,vector<Player>& player);
    void AskAddCard(Deck& deck, vector<Player>& player);
    void AskBankerAddCard(Deck& deck, vector<Player>& player);
    void ShowTable(vector<Player>& player);
    void ShowBankerTable(vector<Player>& player);
    void ShowEndTable(vector<Player>& player);
    void SortPlayer(vector<Player>& player);
    void SortPlayer1(vector<Player>& player);   //將player1移到第0個
    void InSurance(vector<Player>& player);
    bool Double(Deck& deck, vector<Player>& player);
    bool IsSpecialCombination(Player& player);
    void Odds(vector<Player>& player);
    void RoundRank(vector<Player>& player, vector<int>&);
    void Rank(vector<Player>& player);
};

#endif