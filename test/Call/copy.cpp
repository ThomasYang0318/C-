#include <iostream>
using namespace std;

int main(){
    int copy = 1;
    int &reference;
    int *pointer;
    int a, b, c;
    a = copy;
    b = &reference;
    &c = *pointer;
    cout << a << " " << b << " " << c;
}