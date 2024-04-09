//#include "Card.h"
#include "BlackJack.h"
#include <iostream>
#include <iomanip> //對齊文字用
#include <algorithm>
#include <vector>


using namespace std;

Hand::Hand() : Card(0){
    bust = 0;
    AceNum = 0;
}

void Hand::AddCard(const Deck& deck){
    cards.push_back(deck.Deal()); // 將卡片添加到手牌的末尾
}

int Hand::GetCardNum(int n){
    return cards[n].GetNum();
}

void Hand::ShowCard(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < cards.size();j++)
            cout << cards[j].PrintCard()[i] << "   ";
        cout << endl;
    }
}

int Hand::CalculateCard(){
    int sum = 0;
    for(int i = 0; i < cards.size(); i++){
        if(cards[i].GetNum() == 1){
            AceNum++;
        } 
    }
    for(int i = 0; i < cards.size(); i++){
        if (cards[i].GetNum() == 11 || cards[i].GetNum() == 12 || cards[i].GetNum() == 13){
            sum += 10;
        }
        else if (cards[i].GetNum() == 1){
            sum += 11;
        }
        else{
            sum += cards[i].GetNum();
        }
    }
    while (sum > 21 && AceNum > 0){
        sum -= 10;
        AceNum--;
    }
    return sum;
}

void Hand::Bust(){
    bust = 1;
}

bool Hand::GetBust(){
    return bust;
}

int Hand::GetHandNum(){
    return cards.size();
}

void Hand::CleanCard(){
    cards.clear();
}

Player::Player() : Hand(){
    static int n = 1;
    name = n;
    money = 10000;
    isBanker = 0;
    bet = 0;
    n++;
}

void Player::BeBanker(){
    isBanker = !isBanker;
}

bool Player::GetBanker(){
    return isBanker;
}

int Player::GetName(){
    return name;
}

int Player::GetMoney(){
    return money;
}

void Player::ChangeMoney(int m){
    money += m;
}

void Player::SetBet(int b){
    bet = b;
}

int Player::GetBet(){
    return bet;
}
int Player::GetHandNum(){
    return cards.size();
}

void Player::CleanHand(){
    CleanCard();
}

void Player::SetAllCardsVisible(){
    for(int i = 0; i < cards.size();i++){
        if(cards[i].GetState() == 0)
            Hand::cards[i].Flop();
    }
}

void Player::Print(){
    if(isBanker)
        cout << "<Banker :" << " Player" << name  << ">"<< endl;
    else
        cout << "<Player" << name << ">" << endl;
    if(isBanker){
        for(int i = 1; i < cards.size();i++){
            if(cards[i].GetState() == 1)
                Hand::cards[i].Flop();
        }
    }
    Hand::ShowCard();
}

void Player::BankerPrint(){
    if(isBanker)
        cout << "<Banker :" << " Player" << name  << ">\tPoint:" << this->CalculateCard() << endl;
    else
        cout << "<Player" << name << endl;
    if(isBanker){
        for(int i = 1; i < cards.size();i++){
            if(cards[i].GetState() == 1)
                Hand::cards[i].Flop();
        }
    }
    Hand::ShowCard();
}

void Player::EndPrint(){
    if(isBanker)
        cout << "<Banker :" << " Player" << name  << ">\tPoint:" << this->CalculateCard() << endl;
    else
        cout << "<Player" << name << ">\t\tPoint:" << this->CalculateCard() << endl;
    Hand::ShowCard();
}

Banker::Banker() : Player(){

}

Game::Game(){}

void Game::ChooseBanker(int p ,vector<Player>& player){
    srand(time(NULL));
    player[rand()%p].BeBanker();
	//cout << "Player "<< rand()%p + 1 << " is banker in this round." << endl; //1~p
}

bool Game::Surrender(int bet, vector<Player>& player){
    bool surrender = false;

    cout << "Would you like to surrender? (Surrendering allows you to retrieve half of your wager.)" << endl // 請問您要投降嗎?(投降能夠拿回一半賭金)
         << "0.No" << endl
         << "1.Yes" << endl;
    cin >> surrender;
    while (cin.fail() || (surrender != 0 && surrender != 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "I don't understand what you said, please enter again." << endl;//我不清楚您說什麼，請再輸入一次
        cin >> surrender;
    }
    
    if(surrender){
        player[0].ChangeMoney(-bet / 2);
        for(int i = 0; i < player.size(); i++){
            if(player[i].GetBanker() == 1){
                player[i].ChangeMoney(bet / 2);
            }
        }
        cout << "You have surrendered and retrieved half of your wager." << endl; //您已經投降並取回一半賭金
        player[0].SetBet(0);
    }
    return surrender;
}

void Game::AskAddCard(Deck& deck, vector<Player>& player){
    SortPlayer1(player);
    int state = 1;
    while(state){
        cout << "------------------------------------------------------------------------"<<endl;
        ShowTable(player);
        if(player[0].CalculateCard() < 21 && player[0].GetHandNum() < 5){
            cout << "Would you like to add a card?" << endl//請問您要補牌嗎？
                 << "0:No" << endl
                 << "1:Yes" << endl;
            cin >> state;
            while (cin.fail() || (state != 0 && state != 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "I don't understand what you said, please enter again." << endl;//我不清楚您說什麼，請再輸入一次
                cin >> state;
            }
            if(state == 1)
                player[0].AddCard(deck);
            else
                break;
        }
        else if(player[0].CalculateCard() == 21){
            cout << "<Player1> Point is 21, waiting for the end of the round." << endl;//<Player1> 點數為21，等待回合結束
            state = 0;
        }
        else if(player[0].CalculateCard() > 21){
            cout << "<Player1> Bust, this round ends." << endl;//<Player1> 爆牌，此回結束
            state = 0;
        }
    }
}

void Game::AskBankerAddCard(Deck& deck, vector<Player>& player){
    SortPlayer(player);
    int state = 1;
    while(state){
        cout << "------------------------------------------------------------------------------"<<endl;
        ShowBankerTable(player);
        if(player[0].CalculateCard() < 21 && player[0].GetHandNum() < 5){
            cout << "Would you like to add a card?" << endl //請問莊家要補牌嗎?
                 << "0:No" << endl
                 << "1:Yes" << endl;
            cin >> state;
            while (cin.fail() || (state != 0 && state != 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "I don't understand what you said, please enter again." << endl;//我不清楚您說什麼，請再輸入一次
                cin >> state;
            }
            if(state == 1)
                player[0].AddCard(deck);
            else
                break;
        }
        else if(player[0].CalculateCard() == 21){
            cout << "<Banker> Point is 21, waiting for the end of the round." << endl;//<Banker> 點數為21，等待回合結束
            state = 0;
        }
        else if(player[0].CalculateCard() > 21){
            cout << "<Banker> Bust, this round ends." << endl;//<Banker> 爆牌，此回結束
            state = 0;
        }
    }
}

void Game::ShowTable(vector<Player>& player){
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker()){
            player[i].Print();
            cout << endl;
        }
    }
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker() != 1){
            player[i].Print();
            cout << endl;
        }
    }
}

void Game::ShowBankerTable(vector<Player>& player){
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker()){
            player[i].BankerPrint();
            cout << endl;
        }
    }
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker() != 1){
            player[i].BankerPrint();
            cout << endl;
        }
    }
}

void Game::ShowEndTable(vector<Player>& player){
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker()){
            player[i].EndPrint();
            cout << endl;
        }
    }
    for (int i = 0; i < player.size(); i++) {
        if(player[i].GetBanker() != 1){
            player[i].EndPrint();
            cout << endl;
        }
    }
}

void Game::SortPlayer(vector<Player>& player){
    for (int i = 0; i < player.size(); i++) {
        if (player[i].GetBanker() == 1) { 
            swap(player[0], player[i]);
            break;
        }
    }
}

void Game::SortPlayer1(vector<Player>& player){
    for (int i = player.size() - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (player[j].GetName() > player[j + 1].GetName()) { 
                swap(player[j], player[j + 1]);
            }
        }
    }
}

void Game::InSurance(vector<Player>& player){
    SortPlayer(player);

    bool state = 0;
    ShowTable(player);
    cout << "Would you like to purchase insurance? (If the banker has 21 points, you can receive double bet." << endl //請問您要購買保險嗎?(若莊家有21點，您可以獲得雙倍賭金)
         << "0.No" << endl  //0.不要
         << "1.Yes" << endl;//1.要
    cin >> state;
    while (cin.fail()  || (state != 0 && state != 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "I don't understand what you said, please enter again." << endl;//我不清楚您說什麼，請再輸入一次
        cin >> state;
    }
    if(state == 1){
        if(player[0].GetCardNum(0) == 1 && player[0].GetCardNum(1) == 10 || player[0].GetCardNum(1) == 11 || player[0].GetCardNum(1) == 12 || player[0].GetCardNum(1) == 13){
            player[0].ChangeMoney(-player[0].GetBet() * 2);
            player[1].ChangeMoney(player[0].GetBet() * 2);
        }
        else{
            player[1].ChangeMoney(player[0].GetBet() / 2);
        }
    }
}

bool Game::Double(Deck& deck, vector<Player>& player){
    int state = 0;
    cout << "Do you want to double your bet? If so, you can only draw one more card" << endl //您要加倍嗎?若是，您只能再抽一張牌
         << "0.No" << endl  //0.不要
         << "1.Yes" << endl;//1.要
    cin >> state;
    while (cin.fail() || (state != 0 && state != 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "I don't understand what you said, please enter again." << endl;//我不清楚您說什麼，請再輸入一次
        cin >> state;
    }
    if(state){
        player[0].AddCard(deck);
        ShowTable(player);
        player[0].SetBet(2 * player[0].GetBet());
        return 1;
    }
    return 0;
}

bool Game::IsSpecialCombination(Player& player) {
    int card1 = player.GetCardNum(0);
    int card2 = player.GetCardNum(1);
    int card3 = player.GetCardNum(2);
    return (card1 == 6 && card2 == 7 && card3 == 8) ||
           (card1 == 6 && card2 == 8 && card3 == 7) ||
           (card1 == 7 && card2 == 6 && card3 == 8) ||
           (card1 == 7 && card2 == 8 && card3 == 6) ||
           (card1 == 8 && card2 == 6 && card3 == 7) ||
           (card1 == 8 && card2 == 7 && card3 == 6);
}

void Game::Odds(vector<Player>& player){
    SortPlayer(player);

    if(player[0].CalculateCard () > 21){
        for(int i = 1; i < player.size(); i++){
            if(player[i].CalculateCard() <= 21){
                player[0].ChangeMoney(- player[i].GetBet());
                player[i].ChangeMoney(player[i].GetBet());
            }
        }
    }
    else{
        for(int i = 1; i < player.size(); i++){
            if(player[i].GetHandNum() >= 5 ){
                if(player[i].CalculateCard() <= 21){
                    player[0].ChangeMoney(-3 * player[i].GetBet());
                    player[i].ChangeMoney(3 * player[i].GetBet());
                    continue;
                }
            }
            else if (IsSpecialCombination(player[i])) {
                if(player[i].CalculateCard() <= 21){
                    player[0].ChangeMoney(-3 * player[i].GetBet());
                    player[i].ChangeMoney(3 * player[i].GetBet());
                    continue;
                }
            }
            else if(player[i].CalculateCard() > 21){
                player[0].ChangeMoney(player[i].GetBet());
                player[i].ChangeMoney(-player[i].GetBet());
            }
            else if(player[i].CalculateCard() <= 21){
                if(player[0].CalculateCard() >= player[i].CalculateCard()){
                    player[0].ChangeMoney(player[i].GetBet());
                    player[i].ChangeMoney(-player[i].GetBet());
                }
                else if(player[0].CalculateCard() < player[i].CalculateCard()){
                    player[i].ChangeMoney(player[i].GetBet());
                    player[0].ChangeMoney(-player[i].GetBet());
                }
            }
        }
    }
}

void Game::RoundRank(vector<Player>& player, vector<int>& startMoney){
    for(int i = 0; i < player.size(); i++) {
        startMoney[i] = player[i].GetMoney() - startMoney[i];
    }

    for(int i = player.size() - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++){
            if( player[j].GetMoney() < player[j + 1].GetMoney()) {
                swap( player[j], player[j + 1]);
                swap( startMoney[j], startMoney[j + 1]);
            }
        }
    }

    // Display the rankings
    cout << "---------------Round Rank Board---------------" << endl << endl;
    cout << "-Rank-|-----Name-----|---Money---|---Change---" << endl;
    for (size_t i = 0; i < player.size(); i++) {
        cout << setw(4) << (i + 1) << "  |" << setw(12) << "Player" << player[i].GetName() << " |" << setw(11) <<  player[i].GetMoney() << "|" << setw(12) <<  startMoney[i] << endl;
    }
    cout << endl;
}
void Game::Rank(vector<Player>& player){
    for(int i = player.size() - 2; i >= 0 ; i--) {
        for(int j = 0; j <= i; j++){
            if( player[j].GetMoney() < player[j + 1].GetMoney()) {
                swap( player[j], player[j + 1]);
            }
        }
    }

    // Display the rankings
    cout << "----------Ranking Board----------" << endl << endl;
    cout << "-Rank-|-----Name-----|---Money---" << endl;
    for (size_t i = 0; i < player.size(); i++) {
        cout << setw(4) << (i + 1) << "  |" << setw(12) << "Player" << player[i].GetName() << " |" << setw(11) << player[i].GetMoney() << endl;
    }
}
