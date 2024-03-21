#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    string s2;
    while(true){
        cin >> s1;
        cin >> s2;

        if(s1 == "0" && s2 == "0")
            break;
        int count = 0;
        int a = 0;
        for(int i = 0; i < s2.size(); i++){
            if(s1[a] == s2[i]){
                count++;
                a++;
            }
            if(s1.size() == a){
                break;
            }
        }
        if(s1.size() == count)
            cout << "true" << endl;
        else 
            cout << "false"<< endl;
    }
}