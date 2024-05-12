#include "Player.h"

Player::Player(){
    
}

Player::Player(int y, int x){
    this->x = x;
    this->y = y;
}

void Player::Move(int dx, int dy){
    x += dx;
    y += dy;
}

int Player::GetX(){
    return x;
}

int Player::GetY(){
    return y;
}

void Player::Display(){
    cout << "Player is at (" << x << ", " << y << ")" << endl;
}

// bool Player::IsNeighbor(Box &box){
//     for(int i = 0; i < box.GetSize(); i++){
//         if ((box.GetX(i) == x) && (box.GetY(i) - y == 1 || box.GetY(i) - y == -1)
//            || (box.GetY(i) == y) && (box.GetX(i) - x == 1 || box.GetX(i) - x == -1)){
//             return 1;
//         }
//     }
// }