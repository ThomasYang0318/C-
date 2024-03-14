#include <iostream>
#include <cstring>
using namespace std;

bool check(char id[]){
    if(strlen(id) != 10 || (id[1] != '1' && id[1] != '2')){
        return 0;
    }
    else 
        return 1;
};

int main() {
    char id[16];
    cout << "Please Enteran ID Number : ";
    
    cin >> id;
    cout << "Input : " << id << endl;

    
    check(id) == 1 ? cout << "Correct!": cout << "Incorrect!!!";
    
    return 0;
}