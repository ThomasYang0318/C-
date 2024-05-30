#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class BinarySearchTree {
private:
    TreeNode *root;
public:
    BinarySearchTree(TreeNode * = NULL);
    void SetRoot(TreeNode*);
    TreeNode* GetRoot();
    bool InsertNum(int);
    void PrintTree();
    void PrintSubTree(TreeNode*);
    bool FindNum(int);
};

#endif