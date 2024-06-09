#include <iostream>
using namespace std;

class Complex{
public:
    Complex(double re = 0.0, double im = 0.0):re(re), im(im){}
    Complex operator+(const Complex&);
    friend ostream& operator << (ostream& ,const Complex&);
private:
    double re;
    double im;
};

Complex Coplex::