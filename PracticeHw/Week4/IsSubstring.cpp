#include <iostream>
using namespace std;

int main(){
    char s1[100];
    char s2[100];
    cin >> s1;
    cin >> s2;

    int i = 0;
    int j = 0;
    int count = 0;
    for(i = 0; i < 100 && s1[i] != '\0'; i++){
        for(; j < 100 && s2[j] != '\0'; j++){
            if(s1[i] == s2[j]){
                count++;
                break;
            }
        }
    }
    if(i == count)
        cout << "true";
    else 
        cout << "false";
}