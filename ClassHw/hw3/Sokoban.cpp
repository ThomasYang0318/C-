#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    ofstream file("mission.txt", ios::out);
    if(!file){
        cout << "File open error!" << endl;
        exit(1);
        return 0;
    }
    return 0;
}