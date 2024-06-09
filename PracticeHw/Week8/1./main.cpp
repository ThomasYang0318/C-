#include "matrix.h"
#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "What's your matrix size (N * N):";
    cin >> size;
    matrix matrixA(size);
    matrix matrixB(size);
    matrix arithmetic(size);

    cout << "Matrix A :" << endl;
    matrixA.SetMatrix();
    //matrixA.PrintMatrix();

    cout << "Matrix B :" << endl;
    matrixB.SetMatrix();
    

    int state = 0;
    while(state != 4){
        cout << "1.Addition" << endl
             << "2.Subtraction" << endl
             << "3.Multiplication" << endl
             << "4.Exit" << endl;
        cin >> state;
        switch (state){
            case 1:
                arithmetic.add(&matrixA, &matrixB);
                break;
            case 2:
                arithmetic.sub(&matrixA, &matrixB);
                break;
            case 3:
                arithmetic.multiple(&matrixA, &matrixB);
                break;
            case 4:
                break;
            default:
                break;
        }
    }
} 