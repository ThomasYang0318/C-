#include <iostream>
#define NUM 10
using namespace std;    

template <typename K>

void Swap(K *a, K *b){
    K temp = *a;
    *a = *b;
    *b = temp;
}

template <typename Q>

void BiSorting(Q a){
    int left = 0, right = NUM - 1;
    while(left <= right){
        if( a[left] % 2 == 0){
            Swap(&a[left], &a[right]);
            for( int k = right; k < NUM -1 && a[k] < a[k+ 1]; k++){
                Swap(&a[k], &a[k + 1]);
            }
            right--;
        }
        else{
            for(int k = left; k >= 1 && a[k - 1] > a[k]; k--){
                Swap(&a[k], &a[k - 1]);
            }
            left++;
        }
    }
}

int main(){
    int a[NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    BiSorting(a);
    cout  << typeid(a).name() << endl;
    cout << typeid(&a[0]).name() << endl;
    for(int i = 0; i < NUM; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}