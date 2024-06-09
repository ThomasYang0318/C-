#include <cstdlib> 
#include <iostream> 
#include <ctime>
#define magic_HP 15
#define worrior_HP 20 

class role {
public: 
    role(char);
    void attack(role ,int); 
    void setHP(int);
    int getHP();
    int getAttackWay(int);
private:
    int HP;
    int attackWay[3];
};

role::role(char become){
    if (become = 'w') {
        HP = worrior_HP; 
        attackWay[1] = 1; 
        attackWay[2] = 2;
        attackWay[3] = 3;
    }
    else{
        HP = magic_HP; 
        attackWay[1] = 1; 
        attackWay[2] = 1; 
        attackWay[3] = 6;
    }
}

int role::getHP(int inHP){ 
    HP = inHP;
}


int role::setHP(){
    return HP;
}

int role::getAttackWay(int num){ 
    return attackWay[num];
}

void role::attack(role attacked, int num){
    attacked.setHP(attacked.getHP() - attacked.attackWay[num]); 
    cout <<"受到了"<< attacked.attackWay[num]<<"點傷害，";
}
int main()(
int temp;
    cout << " 若 要 成 為 戰 士 請 輸 入 w ， 若 要 成 為 法 師 請 輸 入 m :" < < e n d l ; cin >> temp;
role player (temp);
temp ="m";
role com(temp);
cout «‹ endl <<" int num;
do {
" «endl;