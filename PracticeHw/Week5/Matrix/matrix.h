#ifndef MATRIX_H
#define MATRIX_H
class matrix{
    int N;    //row ,col
    double data[3][3];
public:
    matrix();
    void SetMatrix(int);
    void GetMatrix();
    void PrintMatrix();
    static void add(matrix*, matrix*);
    static void sub(matrix*, matrix*);
    static void multiple(matrix*, matrix*);
    static void divide(matrix*, matrix*);
};

#endif