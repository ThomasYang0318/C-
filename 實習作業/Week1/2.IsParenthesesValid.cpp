#include <iostream>
using namespace std;

int main(){
    char arr[100];
    cin.getline(arr, 100);
    
    int state = 0;
    for(int i = 0; i < 100 && state >= 0; i++){
        if(arr[i] == '(')
            state += 1;
        else if (arr[i] == ')')
            state -= 1;
    }

    if(state == 0)
        cout << "valid";
    else 
        cout << "invalid";
}