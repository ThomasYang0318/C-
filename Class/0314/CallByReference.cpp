#include <iostream>
using namespace std;

void Func1(int a, int *b, int &c){
    a = 30;
    *b = 999; 
    c = 100;
    cout << a << ", " << *b << ", "<< c << endl;
}

int main(){
    int a = 9;
    int &g = a;        //g是a的暱稱
    
    Fun1(a, b, a);
    cout << a << ", " << *b << ", " << a << endl;
    return 0;
}