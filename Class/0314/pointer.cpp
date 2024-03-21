#include <iostream>
using namespace std;

void Func1(int a, int *b){
    a = 30;
    *b = 999; 
    cout << a << ", " << *b << endl;
}

int main(){
    int a = 9;

    int *b;
    int **c;
    int ***d;
    int ****e;

    b = &a;
    c = &b;
    d = &c;
    e = &d;    

    Func1(a, b);   
    cout << a << ", " << b << endl;

    //a == d d要加幾個*
    if(a == ***d) 
        cout << "YES!" << endl;
    return 0;
}