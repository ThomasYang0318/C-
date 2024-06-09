#include "Player.h"

Player::Player(){
    
}

Player::GetMap(vector< vector<char> > m){
    this->map = m;
}

Player::ShowMap(){
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}