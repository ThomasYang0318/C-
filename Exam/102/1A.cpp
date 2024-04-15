#include <iostream>
#include <string>
using namespace std;
class Person{                               //4.5.
public:
    Person(string n, int a);                //4.5.this is constructor don't use 'void'
    void Print();                     //7.lose 'const'

private:
    string name;                      //6.name is const
    int age;
};                                          //2.lose ';'

Person::Person(string n ,int a){       //3.lose 'Person::' 4.
    name = n;                         //6.lose 'const'
    age = a;
}

void Person::Print(){                       //3.lose 'Person::' 7.
    cout << name << " is " << age << " years old." << endl;    //1.no 'using namespace std;'
}

int main(){
    Person p1("John", 15);
    Person p2("Mary", 13);                  //7.
    Person p3("Amy" , 18);                  //5.p3 no name and age
    p1.Print();
    p2.Print();                             //7.
}