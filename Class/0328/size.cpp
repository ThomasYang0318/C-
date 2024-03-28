#include <iostream>
using namespace std;

template <typename A> 
A size(A x){
    return x * x;
}

int main(){
    cout << square(3) << endl;
    cout << square(3.3) << endl;

    return 0;
}