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

    int f[3];
    for(int i = 0; i < 3; i++){
        f[i] = i *10 +i;
    }
    cout << *(f+1) << endl;
    cout << f[1] << endl;
    /*
    cout << "f : " << f << endl;
    cout << "&f[0] : " << &f[0] << endl;

    cout << "f+1 : " << f+1 << endl;
    cout << "&f[1] : " << &f[1] << endl;

    cout << "f+2 : " << f+2 << endl;
    cout << "&f[2] : " << &f[2] << endl;
    */
    return 0;
}