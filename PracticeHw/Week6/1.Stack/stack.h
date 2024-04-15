#ifndef STACK_H
#define STACK_H
#include <vector>
using namespace std;

class Stack{
private:
    vector<int> stackNum;
public:
    Stack();

    void pop();
    void push();
    void empty();
    void top(); 
    void setNum(int);
};
#endif