#include "BiSTree.h"
#include <iostream>
using namespace std;
BisTree::BisTree(Node *r){
    SetRoot(r);
}

void BisTree::SetRoot(Node* r){
    root = r;
}

Node *BisTree::GetRoot(){
    return root;
}
    
bool BisTree::InsertNum(int n){
    if ( root == NULL ){
        root = new Node(n); //呼叫建構子
        return true;
    }
    Node *cur = root;
    while (true){
        if ((*cur).GetNum() == n){
            return false;
        }
        if ((*cur).GetNum() > n){
            if ( (*cur).GetLeft() == NULL){
                (*cur).SetLeft(new Node(n));
                return true;
            }
            else{
                cur = (*cur).GetLeft();
            }
        }
        else{
            if ((*cur).GetRight() == NULL){
                (*cur).SetRight(new Node(n));
                return true;
            }
            else{
                cur = (*cur).GetRight();
            }
        }
    }
}

void BisTree::PrintTree(){
    if(root == NULL){
        cout << "The tree is empty." << endl;
        return;
    }

    PrintSubTree((*root).GetLeft());
    cout << (*root).GetNum() << " ";
    PrintSubTree((*root).GetRight());
    cout <<  endl;
}

void BisTree::PrintSubTree(Node *cur){
    if(cur == NULL)
        return;
    PrintSubTree((*cur).GetLeft());
    cout << (*cur).GetNum() << " ";
    PrintSubTree((*cur).GetRight()); 
}
