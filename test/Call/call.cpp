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
    int name;
    int id;
};

class B : A{
public:
    B() : id(num){
        name = id;
        num++;
        cout << "Constructor : Obj " << id << " of type B. Name is " << name << endl;
    }
    ~B(){
        cout << "Destructor : Obj " << id << " of type B. Name is " << name << endl;
    }
    int name;
    int id;
};

class C : B{
public:
    C() : id(num){
        name = id;
        num++;
        cout << "Constructor : Obj " << id << " of type C. Name is " << name << endl;
    }
    ~C(){
        cout << "Destructor : Obj " << id << " of type C. Name is " << name << endl;
    }
    int name;
    int id;
};

int main(){
    A o1;
    B o2;
    B o3 = o2;
}