#include <iostream>
#include<cmath>
using namespace std;

int main(){
    while(1){
        double h, m;
        cin >> h >> m;
        h = h * 30 + 30 * m / 60;
        m = 6 * m;
        double angle;
        angle = h - m;
        if(angle > 180){
            angle = 360 - angle;
        }
        if(angle < 0){
            angle = -angle;
        }
        cout << round(angle) << endl;
    }
}