#include <iostream>
using namespace std;

int main() {
    int A = 9;
    int *B = &A;

    cout << "A " << A << endl;
    cout << "B " << B << endl;
    cout << "*B " << *B << endl;

    int C[10];
    for ( int i = 0 ; i < 10 ; i++ )
        C[i] = i ;

    B = &C[5];
    cout << "*B after B=&C[5], " << *B << endl;

    (*B)++;
    cout << "(*B++) " << *B << " vs. C[5] " << C[5] << endl;


    cout << "*(C+4) " << *(C+4) << endl;

    int D = 2;
    int* D1=&D;
    int** D2;
    int*** D3;

    D1 = &D;
    D2 = &D1;
    D3 = &D2;

    cout << "***D3 " << ***D3 << endl;

    **D2 = 5;
    cout << "***D3 " << ***D3 << endl;

    *D1 = C[7];
    cout << "***D3 " << ***D3 << endl;

    int E1[10], E2[2][10], E3[3][2][10];
    for ( int k = 0 ; k < 3 ; k++ )
        for ( int j = 0 ; j < 2 ; j++ )
            for ( int i = 0 ; i < 10 ; i++ ) {
                E3[k][j][i] = k*100+j*10+i;
                E2[j][i] = j*10+i;
                E1[i] = i;
            }

    int *F1, *F2[2], *F3[3][2];
    F1 = E1;
    cout << "F1=E1 " << *F1+3 << endl;
    F2[0] = E2[0];
    cout << "F2[0]=E2[0] " << *F2[0]+1 << endl;
    F3[0][0] = E3[0][0];
    cout << "F3[0][0]=E3[0][0] " << *F3[0][0]+7 << endl;

    return 0;
}