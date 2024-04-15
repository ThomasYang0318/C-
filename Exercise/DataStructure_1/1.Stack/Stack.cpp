#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
    _top = -1;
}

void Stack::Push(){
    int num = 0;
    cout << "Enter a number to push : ";
    cin >> num;
    if(_top < MAX - 1){
        _top++;
        stack[_top] = num;
    }
    else{
        cout << "This stack is full." << endl;
    }
}

void Stack::Pop(){
    if(_top == -1){
        cout << "This stack is empty." << endl;
    }
    else{
        cout << stack[_top] << " is popped." << endl;
        stack[_top] = 0;
        _top--;
        cout << "Stack:" << endl;
        for(int i = _top; i >= 0; i--){
            cout << stack[i] << endl;
        }
    }
}

void Stack::Top(){
    if(_top == -1){
        cout << "This stack is empty." << endl;
    }
    else{
        cout << stack[_top];
    }
}
    
void Stack::Reverse(){
    cout << "This stack is reversed." << endl;
    int temp[MAX] = {0};
    for(int i = 0; i <= _top; i++){
        temp[i] = stack[_top - i];
    }
    for(int i = 0; i <= _top; i++){
        stack[i] = temp[i];
    }
}

void Stack::Empty(){
    cout << "This stack is empty." << endl;
    for(int i = 0; i < MAX; i++){
        stack[i] = 0;
    }
    _top = -1;
}

void Stack::IsEmpty(){
    if(_top == -1)
        cout << "This stack is empty." << endl;
    else
        cout << "This stack is not empty." << endl;
}

void Stack::ShowStack(){
    if(_top == -1){
        cout << "This stack is empty." << endl;
    }
    else{
        cout << "Stack:" << endl;
        for(int i = _top; i >= 0; i--){
            cout << stack[i] << endl;
        }
    }
}