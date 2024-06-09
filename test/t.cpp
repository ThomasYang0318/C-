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
    A(const A& o) : id(num){
        name = o.name;
        num++;
        cout << "Copy Constructor : Obj " << id << " of type A. Name is " << name << endl;
    }
    ~A(){
        cout << "Destructor : Obj " << id << " of type A. Name is " << name << endl;
    }
    const int id;
    int name;
};

void swap1(A o1){
    A tmp = o1;
}


int main(){
    A o1;
    swap1(o1);
}