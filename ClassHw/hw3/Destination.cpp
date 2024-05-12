#include "Destination.h"

Destination::Destination(){}

Destination::Destination(int y, int x){
    state = false;
    this->x = x;
    this->y = y;
}

int Destination::GetX(){
    return x;
}

int Destination::GetY(){
    return y;
}

void Destination::ChangeObjectInside(int s){
    state = s;
}

bool Destination::ObjectInside(){
    return state;
}

void Destination::Display(){
    cout << "Destination is at (" << x << ", " << y << ")" << endl;
    cout << "Object is inside: " << ObjectInside() << endl;
}