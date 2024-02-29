#include "time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m, int s){
    hrs = min = sec = 0;  //不會覆蓋輸入值
    SetHrs(h);
    SetMin(m);
    SetSec(s);
}

void Time::Increment(){
    sec++;
    if(sec==60){
        sec = 0;
        min++;
        if(min == 60){
            min = 0;
            hrs++;
            if(hrs == 24){
                hrs = 0;
            }
        }
    }
}

void Time::SetHrs(int h){
    if( 0 <= h && h < 24 )
        hrs = h;
}

void Time::SetMin(int m){
    if( 0 <= m && m < 60 )
        min = m;
}

void Time::SetSec(int s){
    if( 0 <= s && s < 60 )
        sec = s;
}

void Time::SetTime(int h, int m, int s){
    SetHrs(h);
    SetMin(m);
    SetSec(s);
}

void Time::PrintTime(){
    cout << hrs << " : " << min << " : " << sec << endl;
}