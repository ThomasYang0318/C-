#include <iostream>
#include "node.h"
#include "BiSTree.h"
using namespace std;
int main(){
    BisTree tree;
    tree.PrintTree();

    tree.InsertNum(15);
    tree.PrintTree();

    tree.InsertNum(3);
    tree.PrintTree();

    tree.InsertNum(1);
    tree.PrintTree();

    tree.InsertNum(17);
    tree.InsertNum(21);
    tree.InsertNum(18);
    tree.InsertNum(31);
    tree.InsertNum(2);
    tree.PrintTree();
    return 0;
}