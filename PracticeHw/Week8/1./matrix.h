#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;
class matrix{
    int N;    //row ,col
    vector< vector<double> > data;
public:
    matrix(int);
    void SetMatrix();
    void PrintMatrix();
    static void add(matrix*, matrix*);
    static void sub(matrix*, matrix*);
    static void multiple(matrix*, matrix*);
};

#endif