#include <iostream>
#include <string>
using namespace std;

// .  .*  ::  ?: can't be overloaded
//  +  =>  operator + ( A, B )
// i++ =>  operator ++ ( i, 0 )
// ++i =>  operator ++ ( i )
// try catch
// <<  overriding 

class PhoneNumber{
    friend ostream &operator<<(ostream& os, const PhoneNumber& obj){
        os << "(" << obj.areaCode << ") " << obj.exchange << "-" << obj.line;
        return os;
    };
    friend istream &operator>>(istream& is, PhoneNumber& obj){
        is.ignore();
        is >> obj.areaCode;
        is.ignore();
        is >> obj.exchange;
        is.ignore();
        is >> obj.line;
        return is;
    };
private:
    string areaCode;
    string exchange;
    string line;
};

int main() {
    PhoneNumber myPhone;

    cout << "Enter phone number in the form (123) 456-7890:" << endl;
    cin >> myPhone;
    cout << "The phone number entered was: " << myPhone << endl;

    return 0;
}