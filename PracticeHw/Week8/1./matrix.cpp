#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix(int s){
    N = s;
    for(int i = 0; i < N ; i++){
        vector<double> temp;
        for(int j = 0; j < N ; j++)
            temp.push_back(0);
        data.push_back(temp);
    }
}

void matrix::SetMatrix(){
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
    matrix C(A->N);
    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++){
            for(int r = 0; r < A->N; r++)
                C.data[i][j] += A->data[i][r] * B->data[r][j];
        }
    }

    for(int i = 0; i < A->N ; i++){
        for(int j = 0; j < A->N ; j++){
            cout << C.data[i][j] << " ";
        }
        cout << endl;
    }
}