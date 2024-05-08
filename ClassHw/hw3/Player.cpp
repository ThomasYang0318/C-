#include "Player.h"

Player::Player(Map& map) {
    // Find player's initial position
    for (int i = 0; i < map.rows; ++i) {
        for (int j = 0; j < map.cols; ++j) {
            if (map.OriginalMap[i][j] == '0') {
                PlayerX = j;
                PlayerY = i;
                initialPlayerX = j;
                initialPlayerY = i;
                break;
            }
        }
    }
    Box box(map);
}

void Player::move(Map& map, int dx, int dy){
    newPlayerX = PlayerX + dx;
    newPlayerY = PlayerY + dy;

    if (map.map[newPlayerY][newPlayerX] == '-' || map.map[newPlayerY + dy][newPlayerX + dx] == '2') {
        map.map[PlayerY][PlayerX] = '-';
        map.map[newPlayerY][newPlayerX] = '0';
        PlayerX = newPlayerX;
        PlayerY = newPlayerY;
    }else if(map.map[newPlayerY][newPlayerX] == '1'){
        // Check if there is a box in front of the player
        // If there is, move the box
        if(map.map[newPlayerY + dy][newPlayerX + dx] == '-'){
            push(dx, dy);
            map.map[PlayerY][PlayerX] = '-';
            map.map[newPlayerY][newPlayerX] = '0';
            map.map[newPlayerY + dy][newPlayerX + dx] = '1';
            PlayerX = newPlayerX;
            PlayerY = newPlayerY;
        }
        // If there is no box, do nothing
        // If there is a box and a wall, do nothing
    }
}

void Player::push(int dx, int dy) {
    
}

void Player::PrintPlayer() {
    cout << PlayerX << " " << PlayerY << endl;
}