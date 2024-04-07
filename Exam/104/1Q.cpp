#include <iostream>
//error 1
Class SuperStar{//error 2
    int id = 1;//error 3
    //error 4
    void Show();//error 4,error 5
    int getID(){return id;}//error 4
    //error 4,error 6
}   //error 7

void Show(SuperStar obj){
    cout << "SuperStar No." << obj.getID() << "say\"Hello!\"" << endl;   //error 1,error 4
}

void Show(){    //error 5
    cout << "SuperStar No." << getID() << "say\"Hello!\"" << endl;   //error 1,error 5
}

SuperStar s1(1,18); //error 4,error 6,error 8

int main(){
    int s1 = 2; //error 8
    Show(s1);    //error 8
    return 0;
}