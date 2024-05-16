#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main(){
    string line;
    ifstream file("text.txt", ios::in);
    ofstream output("answer.txt", ios::out);
    map<string , int> wordCount;
    if(file.is_open()){
        while(getline(file, line)){
            stringstream ss(line);
            string word;
            while(ss >> word){
                if(!ispunct(word[0]) && !ispunct(word[word.size()-1]))
                    wordCount[word]++;
                else if(ispunct(word[0]) && word.size() > 1){
                    string temp = word.substr(1, word.size()-1);
                    wordCount[temp]++;
                }
                else if(ispunct(word[word.size()-1]) && word.size() > 1){
                    string temp = word.substr(0, word.size()-1);
                    wordCount[temp]++;
                }
                else 
                    continue;
            }
        }
        file.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }

    for(const auto& pair : wordCount) {
        output << pair.first << " : " << pair.second << endl;
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}