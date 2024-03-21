#include "node.h"

Node::Node(int n, Node* r, Node* l){
    SetNum(n);
    SetRight(r);
    SetLeft(l);
}

void Node::SetRight(Node* r){
    right = r;
}

void Node::SetLeft(Node* l){
    left = l;
}

Node* Node::GetRight(){
    return right;
}

Node* Node::GetLeft(){
    return left;
}

void Node::SetNum(int n){
    number = n;
}

int Node::GetNum(){
    return number;
}