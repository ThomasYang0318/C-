#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
//#include "Box.h"

using namespace std;

class Sokoban{
    int row, col;
    vector< vector<char> > map;
    vector< vector<char> > OriginalMap;
    const char playerSymbol = '0';
    const char destinationSymbol = '2';
    const char wallSymbol = '#';
    const char boxSymbol = '1';
    const char emptySymbol = '-';
    const char boxOnDestinationSymbol = 'I';
public:
    Sokoban();
    void LoadMap();  // 讀取地圖
    // void ShowMap();  // 顯示地圖
    // void ResetMap(const string&, Player&, vector<Destination>&);  // 重置地圖
    vector< vector<char> > GetMap();  // 取得地圖
    //char GetMap(int ,int);  // 取得地圖
    // void ChangeMap(int ,int, char);  // 設定地圖
    // bool CheckGameOver(int, int, vector<Destination>&);  // 檢查遊戲是否結束
    // char GetSymbol(int , int);  // 每種元素的符號
    // bool IsVaildMove(int, int, int, int);  // 檢查是否為合法移動
};

#endif