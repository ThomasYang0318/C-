#include <iostream>

using namespace std;

class Matrix{
    friend osream& operator<<(ostream &os, const Matrix &m){
        for(int i = 0; i < m.row; i++){
            for(int j = 0; j < m.col; j++){
                os << m.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream &is, Matrix &m){
        for(int i = 0; i < m.row; i++){
            for(int j = 0; j < m.col; j++){
                is >> m.data[i][j];
            }
        }
        return is;
    }
    friend Matrix operator+(const Matrix &m1, const Matrix &m2){
        Matrix temp(m1.row, m1.col);
        for(int i = 0; i < m1.row; i++){
            for(int j = 0; j < m1.col; j++){
                temp.data[i][j] = m1.data[i][j] + m2.data[i][j];
            }
        }
        return temp;
    }
    friend Matrix operator-(const Matrix &m1, const Matrix &m2){
        Matrix temp(m1.row, m1.col);
        for(int i = 0; i < m1.row; i++){
            for(int j = 0; j < m1.col; j++){
                temp.data[i][j] = m1.data[i][j] - m2.data[i][j];
            }
        }
        return temp;
    }
    friend Matrix operator*(const Matrix &m1, const Matrix &m2)
private:
    int **data;
    int row, col;
public:
    Matrix(int r, int c){
        row = r;
        col = c;
        data = new int*[row];
        for(int i = 0; i < row; i++){
            data[i] = new int[col];
        }
    }
    void SetData(int r, int c, int d){
        data[r][c] = d;
    }
    int GetData(int r, int c){
        return data[r][c];
    }
    void Print(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix(){
        for(int i = 0; i < row; i++){
            delete [] data[i];
        }
        delete [] data;
    }
};

Matrix operator*(const Matrix &m1, const Matrix &m2){
    Matrix temp(m1.row, m2.col);
    for(int i = 0; i < m1.row; i++){
        for(int j = 0; j < m2.col; j++){
            temp.data[i][j] = 0;
            for(int k = 0; k < m1.col; k++){
                temp.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return temp;
}
int main(){
    
}