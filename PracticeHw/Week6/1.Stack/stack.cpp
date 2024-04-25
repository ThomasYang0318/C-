#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(){
};

void Stack::pop(){
    if(stackNum.empty()){
        cout << "-----------------------" << endl
             << "The stack is empty" << endl;
    }
    else{
        cout << "-----------------------" << endl
             << "Pop number is " << stackNum.back() << endl;
        stackNum.pop_back();
        cout << "Stack :" << endl;
        for(int i = stackNum.size() - 1; i >= 0; i--){
            cout << stackNum[i] << endl;
        }
    }
    //cout << "The number of popped is " << n << endl;
    //stackNum.pop_back();
};

void Stack::push(){
    if(stackNum.size() == 10){
        cout << "-----------------------" << endl
             << "The stack is full" << endl;
    }
    else{
        int n;
        cout << "-----------------------" << endl
             << "Enter a number to push :" << endl;
        cin >> n;
        stackNum.push_back(n);
        cout << "Stack :" << endl;
        for(int i = stackNum.size() - 1; i >= 0; i--){
            cout << stackNum[i] << endl;
        }
    }
};

void Stack::empty(){
    stackNum.clear();   //清空stack
    cout << "-----------------------" << endl
         << "Empty the stack" << endl;
};

void Stack::top(){
    if(stackNum.empty()){
        cout << "-----------------------" << endl
             << "The stack is empty" << endl;
    }
    else{
        cout << "-----------------------" << endl
             << "Top number is " << stackNum.back() << endl;
    }
};

void Stack::setNum(int n){
    stackNum.push_back(n);
};