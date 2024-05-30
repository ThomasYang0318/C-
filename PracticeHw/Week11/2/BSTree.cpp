#include "BSTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(TreeNode *r){
    SetRoot(r);
}

void BinarySearchTree::SetRoot(TreeNode* r){
    root = r;
}

TreeNode *BinarySearchTree::GetRoot(){
    return root;
}
    
bool BinarySearchTree::InsertNum(int n){
    if(root == NULL){
        root = new TreeNode(n);
        return true;
    }

    TreeNode *cur = root;
    while(true){
        if((*cur).val == n){
            return false;
        }
        if((*cur).val > n){
            if((*cur).left == NULL){
                (*cur).left = new TreeNode(n);
                return true;
            }
            else{
                cur = (*cur).left;
            }
        }
        else{
            if((*cur).right == NULL){
                (*cur).right = new TreeNode(n);
                return true;
            }
            else{
                cur = (*cur).right;
            }
        }
    }
}

void BinarySearchTree::PrintTree(){
    if(root == NULL){
        cout << "The tree is empty." << endl;
        return;
    }

    PrintSubTree((*root).left);
    cout << (*root).val << " ";
    PrintSubTree((*root).right);
    cout << endl;
}

void BinarySearchTree::PrintSubTree(TreeNode *cur){
    if(cur == NULL)
        return;
    PrintSubTree((*cur).left);
    cout << (*cur).val << " ";
    PrintSubTree((*cur).right);
}

bool BinarySearchTree::FindNum(int n){
    TreeNode *cur = root;
    while(cur != NULL){
        if((*cur).val == n){
            if((*cur).left == NULL && (*cur).right == NULL){
                cout << "left: NULL, right: NULL" << endl;
            }
            else if((*cur).left == NULL){
                cout << "left: NULL, right: " << (*cur).right->val << endl;
            }
            else if((*cur).right == NULL){
                cout << "left: " << (*cur).left->val << ", right: NULL" << endl;
            }
            else{
                cout << "left: " << (*cur).left->val << ", right: " << (*cur).right->val << endl;
            }
            return 1;
        }
        if((*cur).val > n){
            cur = (*cur).left;
        }
        else{
            cur = (*cur).right;
        }
    }
    return 0;
}
// bool BisTree::InsertNum(int n){
//     if ( root == NULL ){
//         root = new TreeNode(n); //呼叫建構子
//         return true;
//     }
//     Node *cur = root;
//     while (true){
//         if ((*cur).GetNum() == n){
//             return false;
//         }
//         if ((*cur).GetNum() > n){
//             if ( (*cur).GetLeft() == NULL){
//                 (*cur).SetLeft(new TreeNode(n));
//                 return true;
//             }
//             else{
//                 cur = (*cur).GetLeft();
//             }
//         }
//         else{
//             if ((*cur).GetRight() == NULL){
//                 (*cur).SetRight(new TreeNode(n));
//                 return true;
//             }
//             else{
//                 cur = (*cur).GetRight();
//             }
//         }
//     }
// }

// void BisTree::PrintTree(){
//     if(root == NULL){
//         cout << "The tree is empty." << endl;
//         return;
//     }

//     PrintSubTree((*root).GetLeft());
//     cout << (*root).GetNum() << " ";
//     PrintSubTree((*root).GetRight());
//     cout <<  endl;
// }

// void BisTree::PrintSubTree(Node *cur){
//     if(cur == NULL)
//         return;
//     PrintSubTree((*cur).GetLeft());
//     cout << (*cur).GetNum() << " ";
//     PrintSubTree((*cur).GetRight()); 
// }