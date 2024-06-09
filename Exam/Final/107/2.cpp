#include <iostream>
#include <vector> 
#include <string>
#include <map> 

using namespace std;
class Pokemon{
protected:
    int hp;
    string name;
    vector<string> skill;
    static map<string, string> SType;
    friend void Fight(Pokemon *, Pokemon *, int);
    friend ostream operator<<(ostream &, const Pokemon &);
public:
    Pokemon(){
        hp = 100;
        name = "Pokemon";
    }
    void Info const{
        cout << "Hi, I am " << name << ":" << endl;
        cout << " hp: " << hp << endl;  
    }
};

map<string , string> Pokemon::SType;

ostream &operator << (ostream &out, const Pokemon &P){
    P.Info();
    return out;
}

class PoundDing:public Pokemon{
public:
    PoundDing(){
        hp += 25;   name = "PounndDing";
        skill.push_back("Kiss");
        Pokemon::SType["Kiss"] = "Heal";
    }
    void Info() const{
        Pokemon::Info();
        cout << "Skill: Kiss~" << endl;
    }
}

class Pika:public Pokemon{
    friend ostream &operator << (ostream& ,const Pika &);
public:
    Pika(){
        hp += 50;   name = "Pika";
        skill.push_back("Scream");
        Pokemon::SType["Scream"] = "Attack";
    }
    virtual void Info() const{
        Pokemon::Info();
        cout << "Skill: Run!!!" << endl;
    }
};

