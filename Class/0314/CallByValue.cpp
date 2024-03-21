#include <iostream>
using namespace std;

void Func1(int a, int *b){
    a = 30;
    *b = 999; 
    cout << a << ", " << *b << endl;
}
/*
void Func2(int *b){     //(int*) b
    *b = 999;            // b -> b記憶體位置
    cout << *b << endl; //*b -> b的值
}
*/

int main(){
    int a = 9;
    int b = 10;
    Func1(a , &b);           //Call By Value 
    //Func2(&b);          //Call By Pointer
    cout << a << ", " << b << endl;
    return 0;
}