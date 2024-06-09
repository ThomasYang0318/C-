#include <iostream>
using namespace std;

int num = 1;

class A{
public:
    A() : id(num){
        name = id;
        num++;
        cout << "Constructor : Obj " << id << " of type A. Name is " << name << endl;
    }
    ~A(){
        cout << "Destructor : Obj " << id << " of type A. Name is " << name << endl;
    }
    const int id;
    int name;
};

class B : public A{
public:
    B() : id(num){
        name = id;
        num++;
        cout << "Constructor : Obj " << id << " of type B. Name is " << name << endl;
    }
    
    ~B(){
        cout << "Destructor : Obj " << id << " of type B. Name is " << name << endl;
    }
    const int id;
    int name;
};

inline void swap1(A o1, B o2){
    A tmp = o1;
    o1.name = o2.name;
    o2.name = tmp.name;
}

void swap2(A &o1, B &o2){
    A tmp = o1;
    o1.name = o2.name;
    o2.name = tmp.name;
}

int main(){
    A o1;
    B o2;
    swap1(o1, o2);
    {
        static A o3;
        swap2(o3, o2);
    }
    /*
    A a1;
    B b1;
    swap1(a1, b1);
    cout << "After swap1 : " << a1.name << " " << b1.name << endl;
    swap2(a1, b1);
    cout << "After swap2 : " << a1.name << " " << b1.name << endl;
    return 0;
    */


}