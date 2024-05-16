#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string line;
    ifstream file("basic.txt", ios::in);
    ofstream output("output.txt", ios::out);
    string name;
    cin >> name;
    if(file.is_open()){
        while(getline(file, line)){
            if(line.find(name) != string::npos){
                cout << line << endl;
                output << line << endl;
            }
        }
        file.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }

    return 0;
}