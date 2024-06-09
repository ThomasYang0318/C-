#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
public:
    virtual Base operator+(const Base& other) {
        // Base implementation
        return *this;
    }
};

class Derived : public Base {
public:
    Derived operator+(const Derived& other) override {
        // Derived implementation
        return *this;
    }
};

int main() {
    Derived d1, d2;
    d1 + d2;
    return 0;
}   
