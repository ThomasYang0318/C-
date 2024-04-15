#include "Stack.h"
#include <iostream>
#include <iomanip> //對齊文字
using namespace std;

int main(){
    Stack stack;
    cout << "This is a stack." << endl;
    while(1){
        cout << "-----------------------------------" << endl
             << "What you want to do in this stack :" << endl
             << "1. Push" << setw(23) << "5. Empty" << endl
             << "2. Pop"  << setw(26) << "6. IsEmpty"<< endl
             << "3. Top" << setw(28) << "7. ShowStack"<< endl
             << "4. Reverse"<< setw(19)  << "8. Exit"<< endl;
        int state = 0;
        cin >> state;
        switch (state){
            case 1: 
                stack.Push();
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.Top();
                break;
            case 4:
                stack.Reverse();
                break;
            case 5:
                stack.Empty();
                break;
            case 6:
                stack.IsEmpty();
                break;
            case 7:
                stack.ShowStack();
                break;
            case 8:
                cout << "Thanks for using." << endl;
                return 0;
        }
    }
}