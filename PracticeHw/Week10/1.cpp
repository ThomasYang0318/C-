#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    while(1){
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        if(s == "0"){
            cout << "Bye~" << endl;
            return 0;
        }
        else if(s.empty()){
            cout << "Please enter a string." << endl;
        }
        else {
            vector<string> words;
            stringstream ss(s);
            string str("");
            while(ss >> str){
                words.push_back(str);
            }
            if(words.empty()){
                cout << "This string is empty." << endl;
                continue;
            }
            cout << "The lest word length is: " << words.back().length() << endl;
        }
    }
}