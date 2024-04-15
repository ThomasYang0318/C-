#ifndef STACK_H
#define STACK_H
#define MAX 10

class Stack{
    int stack[MAX];
    int _top;
public:
    Stack();

    void Push();
    void Pop();
    void Top();
    void Reverse();
    void Empty();
    void IsEmpty();
    void ShowStack();
};
#endif