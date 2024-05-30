#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    while(1){
        cout << "Enter a string: ";
        cin >> s;
        if(s == "0"){
            break;
        }
        cout << "Reverse string: ";
        for(int i = 0; i < int(s.size()); i++){
            cout << s[s.size() - i - 1] ;
        }
        cout << endl << "-------------------"<< endl;
    }
}