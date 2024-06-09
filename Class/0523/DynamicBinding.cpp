#include <iostream>

using namespace std;

class A{
public:
    virtual void f(){
        cout << "A::f()" << endl;
    }
};

class B : public A{
public:
    // void f(){
    //     cout << "B::f()" << endl;
    // }
};

class C : public B{
public:
    void f(){
        cout << "C::f()" << endl;
    }
};


void DB(A *p){
    p->f();
};

int main(){
    A a;
    B b;
    C c;
    cout << "Static Binding: " << endl;
    a.f();
    b.f();
    c.f();
    cout << "Dynamic Binding: " << endl;
    DB(&a);
    DB(&b);
    DB(&c);
    return 0;
}
