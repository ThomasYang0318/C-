#include <iostream>
#include <vector>

using namespace std;

class MyInt_1{                       //E2
    friend ostream &operator << (ostream &, const MyInt_1 &);  //E6 ??????
public:
    MyInt_1(int i = 1) : n(i) {}     //E4
    void SetN(int num) { n = num; }    
    int GetN()         { return n; }
    virtual void Multiply() const = 0;     //E3 & E7 add "virtual" and "const"
    virtual void Increment(){ n+=1; }      
protected:                              //E1 private -> protected
    int n;                          
};

class MyInt_2 : public MyInt_1{      //E2 :: -> :
public:
    MyInt_2(int i) : MyInt_1(i) {}   
    int GetN() { return n+2; }       //E1
    void Increment(){ n+=2; }        //E1
    void Multiply() const            //E1&E7 add "const"
        { cout << n << endl;}       
};

class MyInt_3 : public MyInt_2{     //E4&E2 :: -> :
public:
    MyInt_3(int i = 3) : MyInt_2(i) {}   //E4 MyInt_1 -> MyInt_2
    int GetN() { return n+3; }       //E1
    void Increment(){ n+=3; }        //E1
};

MyInt_1 &operator + (MyInt_1 &a, MyInt_1 &b){  //E5 void -> MyInt_1 
    a.SetN(a.GetN() * b.GetN());           
    return a;                                  //E5
}

ostream &operator << (ostream &out, const MyInt_1 &a){  
    out << a.n << " ";               //E6
    return out;
}

int main(){
    cout << "Q1" << endl;
    {
    MyInt_2 a(2);                    //E2
    MyInt_3 b;                       //E2
    const MyInt_3 c;                 //E7
    cout << a << b << a + b << endl; //E5
    c.Multiply();                    //E7
    }
    cout << "----------------------" <<endl;
    cout << "Q2(a)" << endl;
    {
        MyInt_2 a(2);                    
        a.Increment();
        cout << a << ", " << a.GetN() << endl;
        // 4, 6
    }
    cout << "----------------------" <<endl;
    cout << "Q2(b)" << endl;
    {
        MyInt_3 a(111);                    
        a.Increment();
        cout << a << ", " << a.GetN() << endl;
        // 114, 117
    }
    cout << "----------------------" <<endl;
    cout << "Q2(c)" << endl;
    {
        MyInt_2 a(2);                    
        MyInt_3 b;
        cout << a << ", " << b << ", " << a + b << endl;
        // 2, 3, 6
    }
    cout << "----------------------" <<endl;
    cout << "Q2(d)" << endl;
    {
        MyInt_2 a(2);                    
        MyInt_3 b;
        vector<MyInt_2> vec;
        for(int i = 0; i < 4; i++){
            if(i % 2 == 0){
                a.SetN(i);
                vec.push_back(a);
            }
            else{
                b.SetN(i);
                vec.push_back(b);
            }
        }
        for(vector<MyInt_2>::iterator it = vec.begin(); it != vec.end(); it++){
            (*it).Increment();
            cout << *it << ", " << (*it).GetN() << endl;
        }
        // 2 , 4
        // 3 , 5
        // 4 , 6
        // 5 , 7
    }
    cout << "----------------------" <<endl;
    cout << "Q2(e)" << endl;
    {
        vector<MyInt_1*> vec;
        for(int i = 0; i < 4; i++){
            if(i % 2 == 0)
                vec.push_back(new MyInt_2(i));
            else
                vec.push_back(new MyInt_3(i));
        }
        for(vector<MyInt_1*>::iterator it = vec.begin(); it != vec.end(); it++){
            (**it).Increment();
            cout << **it << ", " << (**it).GetN() << endl;
        }
        // 2 , 2
        // 4 , 4
        // 4 , 4
        // 6 , 6
    }
}