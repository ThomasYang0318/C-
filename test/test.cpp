#include <iostream>
using namespace std;
static int a = 0;
class A{
public:
    A();
    A(const A&);
};
A::A(){a++;}
A::A(const A&){a++;}

class B{
private:
    A cardset[52];
public:
    A Do();
};

class C{}

A B::Do(){
    return cardset[0]
}

int main(){
    B b;
    A d = c;
    cout << a;
} 