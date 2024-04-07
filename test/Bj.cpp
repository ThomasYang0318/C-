#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#include <string>

// 定義牌的類別
class Card {
public:
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(Rank r, Suit s) : rank(r), suit(s), faceUp(true) {}

    int GetValue() const {
        if (rank > TEN) {
            return 10;
        }
        if (rank == ACE) {
            return 11; // 預設ACE為11，之後根據情況調整
        }
        return rank;
    }

    void Flip() {
        faceUp = !faceUp;
    }

    void Display() const {
        if (faceUp) {
            const char* rank_str[] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
            const char* suit_str[] = { "♣", "♦", "♥", "♠" };
            std::cout << rank_str[rank] << suit_str[suit];
        } else {
            std::cout << "XX"; // 暗牌顯示
        }
    }

    Rank GetRank() const {
        return rank;
    }

    Suit GetSuit() const {
        return suit;
    }

private:
    Rank rank;
    Suit suit;
    bool faceUp;
};

// 定義玩家的類別
class Player {
public:
    Player() : money(10000), bet(0), active(true) {}

    void AddCard(Card c) {
        hand.push_back(c);
        AdjustForAce();
    }

    void AdjustForAce() {
        int totalValue = GetHandValue();
        if (totalValue > 21) {
            for (Card& c : hand) {
                if (c.GetRank() == Card::ACE && c.GetValue() == 11) {
                    // 將ACE從11調整為1
                    c = Card(Card::ACE, c.GetSuit());
                    if (GetHandValue() <= 21) {
                        break;
                    }
                }
            }
        }
    }

    int GetHandValue() const {
        int totalValue = 0;
        for (const Card& c : hand) {
            totalValue += c.GetValue();
        }
        return totalValue;
    }

    void DisplayHand() const {
        for (const Card& c : hand) {
            c.Display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    int GetMoney() const {
        return money;
    }

    void UpdateMoney(int amount) {
        money += amount;
    }

    void PlaceBet(int amount) {
        bet = amount;
        money -= bet;
    }

    int GetBet() const {
        return bet;
    }

    bool IsActive() const {
        return active;
    }

    void SetActive(bool status) {
        active = status;
    }

    // 其他玩家相關的函數...

private:
    std::vector<Card> hand;
    int money;
    int bet;
    bool active;
};

// 定義遊戲的類別
class Game {
public:
    Game() : round(0), minimumBet(100) {}

    void InitializeGame(int num_players) {
        // 初始化玩家
        for (int i = 0; i < num_players; ++i) {
            players.push_back(Player());
        }
        // 選擇莊家...
        ChooseDealer();
    }

    void PlayRound() {
        // 遊戲的每一輪...
        std::cout << "第 " << round + 1 << " 輪開始" << std::endl;

        // 洗牌
        ShuffleDeck();

        // 下注
        for (Player& player : players) {
            if (player.IsActive()) {
                int bet;
                do {
                    std::cout << "玩家 " << &player - &players[0] + 1 << " 的下注金額: ";
                    std::cin >> bet;
                } while (bet < minimumBet);
                player.PlaceBet(bet);
            }
        }

        // 發牌
        DealInitialCards();

        // 玩家動作
        PlayerActions();

        // 莊家動作
        DealerActions();

        // 結算
        Payout();

        // 更新輪數
        round++;

        // 選擇下一輪的莊家
        ChooseDealer();
    }

    // 其他遊戲相關的函數...

private:
    std::vector<Card> deck;
    std::vector<Player> players;
    int round;
    int minimumBet;
    int dealerIndex;

    void ShuffleDeck() {
        // 創建一副新牌
        deck.clear();
        for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
            for (int r = Card::ACE; r <= Card::KING; ++r) {
                deck.push_back(Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
            }
        }
        // 洗牌
        std::random_shuffle(deck.begin(), deck.end());
    }

    void DealInitialCards() {
        // 向每位玩家發兩張牌
        for (int i = 0; i < 2; ++i) {
            for (Player& player : players) {
                if (player.IsActive()) {
                    player.AddCard(deck.back());
                    deck.pop_back();
                }
            }
        }
    }

    void PlayerActions() {
        // 玩家決定是否加牌或其他動作
        // ...
    }

    void DealerActions() {
        // 莊家決定是否加牌
        // ...
    }

    void Payout() {
        // 結算賠金
        // ...
    }

    void ChooseDealer() {
        // 選擇莊家
        // ...
    }
};

int main() {
    int num_rounds, num_players;
    std::cout << "請輸入要玩的局數: ";
    std::cin >> num_rounds;
    std::cout << "請輸入玩家人數: ";
    std::cin >> num_players;

    Game blackjack;
    blackjack.InitializeGame(num_players);

    for (int i = 0; i < num_rounds; ++i) {
        blackjack.PlayRound();
        // 輸出每輪結果...
    }

    // 輸出遊戲最終結果...

    return 0;
}

