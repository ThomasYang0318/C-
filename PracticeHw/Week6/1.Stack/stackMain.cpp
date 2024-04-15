#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;

int main(){
    Stack stack;
    
    string s;
    cout << "Enter 1 ~ 10 numbers, those numbers are pushed into the stack" << endl;
    getline(cin, s);
    stringstream ss(s);
    //vector<int> v;
    int num;
    while (ss >> num){
        stack.setNum(num);
    }

    int state = 0;
    while(state != 5){
        cout << "-----------------------" << endl
             << "What do you want to do?" << endl
             << "1. push" << endl
             << "2. pop" << endl
             << "3. empty" << endl
             << "4. top" << endl
             << "5. exit" << endl;
        cin >> state;
        switch (state){
            case 1:
                stack.push();
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.empty();
                break;
            case 4:
                stack.top();
                break;
            case 5:
                cout << "Thanks for using.";
                break;
        }
    }
}