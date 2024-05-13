#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
#include "Destination.h"
//#include "Box.h"

using namespace std;

class Map {
    int row, col;
    vector< vector<char> > map;
    vector< vector<char> > OriginalMap;
public:
    Map();
    void LoadMap(const string&, Player&, vector<Destination>&);  // 讀取地圖
    void ShowMap();  // 顯示地圖
    void Reset(Player&, vector<Destination>&);  // 重置地圖
    char GetMap(int ,int);  // 取得地圖
    void ChangeMap(int ,int, char);  // 設定地圖
    bool CheckGameOver(int, int, vector<Destination>&);  // 檢查遊戲是否結束
    //void Action(int, int, Player&);  // 玩家操作
    //virtual ~Map() = default;
    //virtual char GetSymbol() = 0;  // 每種元素的符號
    //virtual void Display();  // 顯示地圖
    //void Display();  // 顯示地圖，並標示玩家位置
};

#endif