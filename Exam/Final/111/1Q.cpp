#include <iostream>
#include <vector>

using namespace std;

class MyInt_1{                       //E2
                                     //E6
public:
    MyInt_1(int i = 1) : n(i) {}     //E4
    void SetN(int num) { n = num; }    
    int GetN()         { return n; }
    void Multiply() = 0;             //E3 & E7
    virtual void Increment(){ n+=1; }      
private:                             //E1
    int n;                          
};

class MyInt_2 :: public MyInt_1{     //E2
public:
    MyInt_2(int i) : MyInt_1(i) {}   
    int GetN() { return n+2; }       //E1
    void Increment(){ n+=2; }        //E1
    void Multiply()                  //E1&E7
        { cout << n << endl;}       
};

class MyInt_3 :: public MyInt_2{     //E4&E2
public:
    MyInt_3(int i = 3) : MyInt_1(i) {}   //E4
    int GetN() { return n+3; }       //E1
    void Increment(){ n+=3; }        //E1
};

void &operator +(MyInt_1 &a, MyInt_1 &b){ //E5  
    a.SetN(a.GetN() * b.GetN());           
    return a;                               //E5
}

ostream &operator << (ostream &out, const MyInt_1 &a){  
    out << a.n << " ";               //E6
    return out;
}

int main(){
    MyInt_2 a(2);                    //E2
    MyInt_3 b;                       //E2
    const MyInt_3 c;                 //E7
    cout << a << b << a + b << endl; //E5
    c.Multiply();                    //E7
    return 0;
}