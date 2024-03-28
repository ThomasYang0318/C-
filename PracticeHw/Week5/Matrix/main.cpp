#include "matrix.h"
#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "What's your matrix size (N * N):";
    cin >> size;
    matrix matrixA;
    matrix matrixB;
    matrix arithmetic;

    matrixA.SetMatrix(size);
    matrixA.GetMatrix();
    //matrixA.PrintMatrix();

    matrixB.SetMatrix(size);
    matrixB.GetMatrix();

    int state = 0;
    while(state != 5){
        cout << "1.Addition" << endl
             << "2.Subtraction" << endl
             << "3.Multiplication" << endl
             << "4.Division" << endl
             << "5.Exit" << endl;
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
                arithmetic.divide(&matrixA, &matrixB);
                break;
            case 5:
                break;
            default:
                break;
        }
    }
    //matrixB.PrintMatrix();

    //Matrix matrixB;
    //Matric arithmetic;
    /*
    int state = 0;
    while(state != 5){
        cout << "1.Addition" << endl
             << "2.Subtraction" << endl
             << "3.Multiplication" << endl
             << "4.Division" << endl
             << "5.Exit" << endl;
        cin >> state;
        switch (state){
            case 1:
                arithmetic.
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        
            default:
                break;
        }
    }
    */

} 