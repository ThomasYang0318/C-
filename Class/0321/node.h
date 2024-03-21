#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    int number;
    Node *right, *left; //pointer可以指向其他東西
public:
    Node(int, Node* = NULL, Node* = NULL);  //建構子
    void SetRight(Node*);
    void SetLeft(Node*);
    Node* GetRight();
    Node* GetLeft();
    void SetNum(int);
    int GetNum();
};
#endif