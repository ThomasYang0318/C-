#include <iostream>
using namespace std;

int main(){
    int multiplier , multiplicand;
    cin >> multiplier >> multiplicand;
    
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(i == j || (i == multiplier && j == multiplicand)){
                if(i * j < 10)
                    cout << i << "*" << j << "= " << i * j << " ";
                else
                    cout << i << "*" << j << "=" << i * j << " ";
            }
            else 
                cout << "       ";
        }
        cout << endl;
    }
}