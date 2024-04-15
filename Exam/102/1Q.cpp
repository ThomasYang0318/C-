#include <iostream>
#include <string>

class Person{                       //4.5.
public:
    void Person(string n, int a);   //4.5.
    void Print();                   //7.

private:
    const string name;              //6.
    int age;
}                                   //2.

void Person(string n ,int a){       //3.4.
    name = a;                       //6.
    age = a;
}

void Print(){                       //3.7.
    cout << name << "is" << age << "years old." << endl;    //1.
}

int main(){
    Person p1("John", 15);
    const Person p2("Mary", 13);    //7.
    Person p3;                      //5.
    p1.Print();
    p2.Print();                     //7.
}