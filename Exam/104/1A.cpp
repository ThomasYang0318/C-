#include <iostream>
using namespace std;        //error 1 :lose "using namespace std;"
class SuperStar{            //*error 2 :SuperStar() lose "(int, int)" => wrong ,Ans: Class => class
    int id, age;                 //*error 3 :Can't initialize here
public:                     //error 4 :lose "public:"
    void Show();            //error 4 :lose "public:",*error 5 :lose "int" => wrong
    int getID(){return id;} //error 4 :lose "public:"
    SuperStar(int id, int age) : id(id) , age(age){};    //error 4 :lose "public:",error 6 :lose ":lose "SuperStar();" => lose constructor
};                          //error 7 :lose ";"

void Show(SuperStar obj){
    cout << "SuperStar No." << obj.getID() << " say\"Hello!\"" << endl;   //error 1 :cout & endl lose "std::",error 4:lose "public:" so getID() is private
}


void SuperStar::Show(){             //error 5:lose "int" => wrong
    cout << "SuperStar No." << getID() << " say\"Hello!\"" << endl;      //error 1 :cout & endl lose "std::",error 5
}


SuperStar s1(1, 18);         //error 4,error 6 :lose constructor so can't use "SuperStar",error 8

int main(){
    //s1.id = 2;              //error 8
    Show(s1);               //error 8
    return 0;
}