#include <iostream>
using namespace std;

template <typename T>
T sum(T* list, int n){
    T sum = 0;
    for(int i = 0; i < n; i++){
        sum += list[i];
    }
    return sum;
}

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double b[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};

    cout << sum(a, 10) << endl;
    cout << sum(b, 10) << endl;
}