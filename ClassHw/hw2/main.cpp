#include <iostream>
#include "Card.h"
#include "BlackJack.h"
using namespace std;

int main() {
    Game game;
    Deck deck;
    const vector<Card>& cards = deck.getCards();
    deck.Shuffle(deck);

    cout << "--------------------Welcome to BlackJack Game--------------------" << endl << endl;
    int round = 0;
    cout << "How many rounds do you want to play: ";//請問您要玩幾局：
    cin >> round;
    while (cin.fail() || round <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Could you please enter the number of rounds again? " << endl;//我不清楚您說什麼，請再輸入一次
        cin >> round;
    }

    int player_num = 0;

    cout << "Please enter the number of players(2 to 4): ";//請輸入玩家人數(2 ~ 4人)：
    cin >> player_num;
    while (cin.fail() || player_num < 2 || player_num > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter the number of players again." << endl;//我不清楚您說什麼，請再輸入一次
        cin >> player_num;
        if(player_num < 2 || player_num > 4){
            cout << "Please enter a number between 2 and 4 for the number of players. " << endl;//請輸入2 ~ 4人
        }
        else{
            break;
        }
    }
    cout << "--------------------Game Start--------------------" << endl << endl;
    cout << "You are Player1" << endl << endl;
    vector<Player> player(player_num);

    for(int roundNum = 1; roundNum <= round && player[0].GetName() == 1 && player.size() >= 2; roundNum++){
        game.SortPlayer1(player);
        cout << "--------------------------Round" << roundNum << "--------------------------" << endl;
        vector<int> startMoney;
        for(int i = 0; i < player.size(); i++){
            startMoney.push_back(player[i].GetMoney());
        }

        int bet = 0;
        while (true) {
            cout << "Your wager:" << player[0].GetMoney() << endl;  //您的賭金：
            cout << "How much would you like to bet? (Minimum bet is 100): ";    //請問您要下注多少(底注為100)：
            cin >> bet;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter again." << endl; //我不清楚您說什麼，請再輸入一次
            } 
            else if (bet < 100) {
                cout << "The bet amount cannot be lower than the minimum bet." << endl; //下注金額不可低於底注
            }
            else if (bet > player[0].GetMoney()) {
                cout << "The bet amount cannot exceed your wager." << endl; //下注金額不可超過您的賭金
            }
            else {
                break;
            }
        }

        for(int i = 0; i < player.size(); i++){
            player[i].SetBet(bet);
        }

        if(roundNum == 1){
            game.ChooseBanker(player.size(), player);
        }
        else{
            for(int i = player.size() - 2; i >= 0; i--){
                for(int j = 0; j <= i; j++){
                    if(player[j].GetMoney() < player[j + 1].GetMoney())
                        swap(player[j], player[j + 1]);
                }
            }
            player[0].BeBanker();
        }

        // 發牌給玩家和莊家2
        for(int i = 0; i < 2; i++){
            for (int j = 0; j < player.size(); j++) {
                player[j].AddCard(deck);
            }
        }
        game.ShowTable(player);
        game.SortPlayer(player);
        if(player[0].GetCardNum(0) == 1){
            if(player[0].GetBanker() != 1)
                game.InSurance(player);
        }
    
        game.SortPlayer1(player);
        if(player[0].GetBanker() == 1){
            //其他玩家補牌
            for (int i = 1; i < player.size(); i++) {
                if (player[i].GetBanker() != 1) {
                    cout << "It's Player " << i + 1 << "'s turn. Would Player " << i + 1 << " like to draw another card?"<< endl;//輪到Player  ，請問Player 要補牌嗎？
                    while (player[i].CalculateCard() <= 11) {
                        cout << "Player " << i + 1 << " wants to draw another card." << endl; //Player 要補牌
                        player[i].AddCard(deck);
                        game.ShowTable(player);
                    }
                    if(player[i].CalculateCard() >= 17){
                        cout << "Player " << i + 1 << " doesn't want to draw another card." << endl;//Player 不要補牌
                    }
                    else{
                        player[i].AddCard(deck);
                        game.ShowTable(player);
                    }
                }
            }
            
            //莊家補牌
            for (int i = 0; i < player.size(); i++) {
                game.SortPlayer(player);
                if(player[i].GetBanker() == 1){
                    cout << "It's the banker's turn. Does the banker want to draw another card?" << endl; //輪到莊家，請問莊家要補牌嗎？
                    while(player[i].CalculateCard() < 17){
                        cout << "The banker's points are below 17, so another card is automatically drawn." << endl;//因為莊家點數未到17點，自動補牌
                        player[i].AddCard(deck);
                        // 將莊家亮的牌都設為正面
                        game.ShowBankerTable(player);
                    }
                    game.ShowBankerTable(player);
                }
            }

            game.AskBankerAddCard(deck, player);
            //算賭金
            game.Odds(player);
        }
        else if(player[0].GetBanker() != 1){
            if(game.Surrender(bet, player) != 1){
                if(player[0].CalculateCard() == 11){
                    if(game.Double(deck, player) == 0){
                        game.AskAddCard(deck, player);
                    }
                }
                else{
                    game.AskAddCard(deck, player);
                }
            }

            //其他玩家補牌
            for (int i = 1; i < player.size(); i++) {
                if (player[i].GetBanker() != 1) {
                    cout << "It's Player " << i + 1 << "'s turn. Would Player " << i + 1 << " like to draw another card?"<< endl;//輪到Player  ，請問Player 要補牌嗎？
                    while (player[i].CalculateCard() <= 11) {
                        cout << "Player " << i + 1 << " wants to draw another card." << endl; //Player 要補牌
                        player[i].AddCard(deck);
                        game.ShowTable(player);
                    }
                    if(player[i].CalculateCard() >= 17){
                        cout << "Player " << i + 1 << " doesn't wants to draw another card." << endl;//Player 不要補牌
                    }
                    else{
                        player[i].AddCard(deck);
                        game.ShowTable(player);
                    }
                }
            }
            
            //莊家補牌
            for (int i = 0; i < player.size(); i++) {
                game.SortPlayer(player);
                if(player[i].GetBanker() == 1){
                    cout << "It's the banker's turn. Does the banker want to draw another card?" << endl; //輪到莊家，請問莊家要補牌嗎？
                    while(player[i].CalculateCard() < 17){
                        cout << "The banker's points are below 17, so another card is automatically drawn." << endl;//因為莊家點數未到17點，自動補牌
                        player[i].AddCard(deck);
                        // 將莊家亮的牌都設為正面
                        player[i].SetAllCardsVisible();
                        game.ShowTable(player);
                    }
                    if(player[i].CalculateCard() >= 17){
                        cout << "The banker doesn't want to draw another card." << endl;//莊家不要補牌
                    }
                }
            }
            //算賭金
            game.Odds(player);
        }
        

        //輸出排名
        //game.Rank(player);
        cout << "--------------------------Round" << roundNum << " Finish--------------------------" << endl << endl;
        cout << "There are all player's cards:" << endl << endl;
        for (int i = 0; i < player.size(); i++) {
            player[i].SetAllCardsVisible();
        }
        game.ShowEndTable(player);
        game.SortPlayer1(player);
        game.RoundRank(player, startMoney);
        for(int i = 0; i < player.size(); i++){
            player[i].CleanHand();
            if(player[i].GetBanker()){
                player[i].BeBanker();
            }
        }

        game.SortPlayer1(player);
        for(int i = 0; i < player.size(); i++){
            if(i != 0){
                if(player[i].GetMoney() <= 0){
                    cout << "Player" << player[i].GetName() << " is bankrupt!!!" << endl; //Player 破產!!!
                    cout << "Player" << player[i].GetName() << " has been kicked out of the game." << endl;//Player 被踢出遊戲
                    player.erase(player.begin() + i);
                }
                else if(player[i].GetMoney() > 0 && player[i].GetMoney() < 100){
                    cout << "Player" << player[i].GetName() << "does not have enough remaining wager to meet the minimum bet for the next round" << endl; //Player 剩餘賭金不夠下局底注
                    cout << "Player" << player[i].GetName() << " has been kicked out of the game." << endl;//Player 被踢出遊戲
                    player.erase(player.begin() + i);
                }
            }
            if(i == 0){
                if(player[i].GetMoney() <= 0){
                    cout << "Player1 is bankrupt!!!" << endl; //Player1破產!!!
                    cout << "Player1 has been kicked out of the game, the game is over." << endl;//Player1被踢出遊戲，遊戲結束
                    game.Rank(player);
                    return 0;
                }
                else if(player[i].GetMoney() > 0 && player[i].GetMoney() < 100){
                    cout << "Player1 does not have enough remaining wager to meet the minimum bet for the next round" << endl; //Player1剩餘賭金不夠下局底注
                    cout << "Player1 has been kicked out of the game, the game is over." << endl;//Player1被踢出遊戲，遊戲結束
                    game.Rank(player);
                    return 0;
                }
            }
        }
    }

    game.Rank(player);
    return 0;
}