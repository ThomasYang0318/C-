#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Map::Map(){
    
}

void Map::LoadMap(const string& filename, Player &player, vector<Destination> &destinations) {
    ifstream file(filename, ios::in);

    if (!file) {
        cerr << "Error: Unable to open this file." << std::endl;
        exit(1);
    }

    file >> row >> col;
    cout << row << " " << col << endl;
    file.ignore();
    for (int i = 0; i < row; ++i) {
        string line;
        if (getline(file, line)) {
            vector<char> row_chars;
            for (int j = 0; j < col; j++) {
                row_chars.push_back(line[j]);
                switch (line[j]){
                    case '0':
                        player = Player(i, j);
                        break;
                    case '2':
                        destinations.push_back(Destination(i, j));
                        break;
                }
            }
            map.push_back(row_chars);
            OriginalMap.push_back(row_chars);
        } else {
            cerr << "Error: Unable to read this file." << endl;
            exit(1);
        }
    }

    file.close();
}

// void Map::Action(int dx, int dy , Player &player) {
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if (map[i][j] == '0') {
//                 if (player.Move(dx, dy)) {
//                     map[i][j] = '-';
//                     map[i + dy][j + dx] = '0';
//                     return;
//                 }
//                 // else if(player.IsNeighbor(box)){
//                 //     box.Move(dx, dy);
//                 //     map[i][j] = '0';
//                 //     map[i + dy][j + dx] = '1';
//                 //     return;
//                 // }
//             }
//         }
//     }
// }

void Map::ShowMap() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

char Map::GetMap(int x, int y){
    return map[y][x];
}

void Map::ChangeMap(int x, int y, char c){
    map[y][x] = c;
}

int Map::CheckNeighbor(int x, int y){
    int count = 0;
    do{
        count++;
    } while (map[y][x + 1] == '1' || map[y][x - 1] == '1' || map[y + 1][x] == '1' || map[y - 1][x] == '1');
    return count;
}

void Map::Reset(Player&player, vector<Destination>&destinations) {
    map.clear();
    player = Player();
    destinations.clear();
    LoadMap("mission.txt", player, destinations);
}