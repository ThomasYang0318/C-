#include <iostream>
using namespace std;

template <typename T> 
T square(T x){
    return x * x;
}

/*
int square(int x){
    return x * x;
}
double square(double x){
    return x * x;
}
*/

int main(){
    cout << square(3) << endl;
    cout << square(3.3) << endl;

    return 0;
}