#include <iostream>
using namespace std;

class A{
public:
    void print() {
        cout << "This is Class A : ";
        x();
        y();
        cout << endl;
    }
    void x() { cout << "A.x";}
    void y() { cout << "A.y";}
};

class B : public A{
public:
    void print() {
        cout << "This is Class B : ";
        x();
        y();
        cout << endl;
    }
    virtual void x() { cout << "B.x";}
    void y() { cout << "B.y";}
};

class C : public B{
public:
    void print() {
        cout << "This is Class C : ";
        x();
        y();
        cout << endl;
    }
    void x() { cout << "C.x";}
    virtual void y() { cout << "C.y";}
};

class D : public C{
    void x() { cout << "D.x";}
};

int main(){
    A *AP;
    B *BP;
    C *CP;
    D obj;

    CP = &obj;
    CP->print(); // This is Class C : C.x C.y
    BP = &obj;
    BP->print(); // This is Class B : B.x C.y
    AP = &obj;
    AP->print(); // This is Class A : A.x C.y
    return 0;
}