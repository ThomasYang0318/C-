#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pokemon{
private:                                //E2-Q2
    string name;                        //E2
    vector<string> skill;               //E2, E3
public:
    Pokemon(string n){                  //E4     
        name = n;
    }
    virtual void Info() const = 0;      //E1
};

class Pika : public Pokemon{     
public:
    Pika{                                   //E4-Q  
        skill[0] = "Scream";                //E3-Q
    }     
    Info();                                 //E1-Q
    void Attack(){                          //E5-Q
        cout << name << ":Angry!" << endl;  //E2
        cout << "Skill Burst - " << skill[0] << "~!!" << endl; //E2
    }
    friend void Fight(Pika &A, Pika &B);    //E6, E7
};

friend void Fight(Pika &A, Pika &B){        //E7  //E6-Q
    cout << A->name << " vs " << B->name << endl; //E7-Q
}

int main(){
    const Pika p("Pika");                   //E1, E4
    Pika A("Sleep"), B("Awake");        

    p.Attack();                             //E5            
    Fight(A, B);                            //E6
    
    return 0;
}