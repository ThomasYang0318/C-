#include "Time.h"
#include <iostream>
using namespace std;

TIME::TIME() {
    Hour = Minute = Second = 0;
};

void TIME::setTime(int h, int m, int s) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        Hour = h;
        Minute = m;
        Second = s;
        showTime();
    } 
    else{
        cout << "Error!" << endl;
    }
};

void TIME::setTime(int seconds) {
    if (seconds >= 0 && seconds < 86400) {
        Hour = seconds / 3600;
        seconds -= 3600 * Hour;
        Minute = seconds / 60;
        seconds -= 60 * Minute;
        Second = seconds;
        showTime();
    } 
    else {
        cout << "Error!" << endl;
    }
};

void TIME::showTime() {
    string Period = "AM";
    if (Hour > 12) {
        Hour -= 12;
        Period = "PM";
    }
    if(Hour == 12)
        Period = "PM";
    if(Hour < 10){
         cout << "0" << Hour << ":";
    }
    else{
        cout << Hour << ":";
    }
    if(Minute < 10){
         cout << "0" << Minute << ":";
    }
    else{
        cout << Minute << ":";
    }
    if(Second < 10){
         cout << "0" << Second << Period << " " << endl;
    }
    else{
        cout << Second << Period << " "<< endl;
    }
};
