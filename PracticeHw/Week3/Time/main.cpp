#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Time.h"
using namespace std;

int main() {
    TIME t;
    
    string time;
    stringstream ss("");
    
    int h = 0, m = 0, s = 0;

    cout << "Initial Time is: ";
    t.showTime();

    while (true) {
        cout << "Please set time: ";
        getline(cin ,time);
        if(time == "-1")
            break;
        int space = 0;
        for(int i = 0; i < time.size(); i++)
            space += time[i] == ' ';
        if(space != 0){
            ss << time;
            ss >> h >> m >> s;
            t.setTime(h, m, s);
        }
        else{
            t.setTime(stoi(time));
        }
        ss.clear();
        ss.str("");
    }
    return 0;
}
