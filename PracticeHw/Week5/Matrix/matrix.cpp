#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix(){}

void matrix::SetMatrix(int s){
    N = s;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++)
            data[i][j] = 0;
    }
}

void matrix::GetMatrix(){
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++)
            cin >> data[i][j];
    }
}
void matrix::PrintMatrix(){
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}

void matrix::add(matrix* A, matrix* B){
    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++)
            cout << A->data[i][j] + B->data[i][j]<< " ";
        cout << endl;
    }
}

void matrix::sub(matrix* A, matrix* B){
    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++)
            cout << A->data[i][j] - B->data[i][j]<< " ";
        cout << endl;
    }
}

void matrix::multiple(matrix* A, matrix* B){
    double matrixC[3][3] = {0};
    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++){
            for(int r = 0; r < A->N; r++)
                matrixC[i][j] += A->data[i][r] * B->data[r][j];
        }
    }

    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++){
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix::divide(matrix* A, matrix* B){
    matrix mul;
    if(A->N == 3){
        matrix adj;
        adj.SetMatrix(3);

        double det = 0;
        det =  A->data[0][0] * A->data[1][1] * A->data[2][2] 
            +  A->data[0][1] * A->data[1][2] * A->data[2][0] 
            +  A->data[0][2] * A->data[1][0] * A->data[2][1] 
            -  A->data[0][2] * A->data[1][1] * A->data[2][0] 
            -  A->data[0][0] * A->data[1][2] * A->data[2][1] 
            -  A->data[0][1] * A->data[1][0] * A->data[2][2];
        if(det != 0){
            adj.data[0][0] = A->data[1][1] * A->data[2][2] - A->data[1][2] * A->data[2][1];
            adj.data[0][1] = A->data[0][2] * A->data[2][1] - A->data[0][1] * A->data[2][2];
            adj.data[0][2] = A->data[0][1] * A->data[1][2] - A->data[0][2] * A->data[1][1];
            adj.data[1][0] = A->data[1][2] * A->data[2][0] - A->data[1][0] * A->data[2][2];
            adj.data[1][1] = A->data[0][0] * A->data[2][2] - A->data[0][2] * A->data[2][0];
            adj.data[1][2] = A->data[0][2] * A->data[1][0] - A->data[0][0] * A->data[1][2];
            adj.data[2][0] = A->data[1][0] * A->data[2][1] - A->data[1][1] * A->data[2][0];
            adj.data[2][1] = A->data[0][1] * A->data[2][0] - A->data[0][0] * A->data[2][1];
            adj.data[2][2] = A->data[0][0] * A->data[1][1] - A->data[0][1] * A->data[1][0];
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    adj.data[i][j] = 1.0 / det * adj.data[i][j];
                }
            }
        }
        mul.multiple(&adj, B);
    }
    else if(A->N == 2){
        matrix adj;
        adj.SetMatrix(2);

        double det = 0;
        det =  A->data[0][0] * A->data[1][1] 
            -  A->data[0][1] * A->data[1][0];
        
        if (det != 0) {
            adj.data[0][0] = A->data[1][1];
            adj.data[0][1] = -A->data[0][1];
            adj.data[1][0] = -A->data[1][0];
            adj.data[1][1] = A->data[0][0];

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    adj.data[i][j] = 1.0 / det * adj.data[i][j];
                }
            }
        }
        mul.multiple(&adj, B);
    } 
}