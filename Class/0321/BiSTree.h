#ifndef BISTREE_H
#define BISTREE_H
#include "node.h"

class BisTree{
    Node *root;
    void PrintSubTree(Node*);
public:
    BisTree(Node * = NULL);
    void SetRoot(Node*);
    Node* GetRoot();
    bool InsertNum(int);
    void PrintTree();
};
#endif