#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BSTree.h"

using namespace std;

int main(){
    BinarySearchTree tree;
    string s;
    cout << "Input your numbers…" << endl;
    getline(cin, s);

    stringstream ss(s);
    string num;
    while(ss >> num){
        tree.InsertNum(stoi(num));
    }

    // cout << "The tree is: " << endl;
    // tree.PrintTree();

    while(1){
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter a number you want to find (Enter -1 to exit) : ";
        cin >> num;
        if(num == "-1"){
            cout << "Bye~" << endl;
            break;
        }
        else if(!tree.FindNum(stoi(num))){
            cout << "The value is not in this binary search tree." << endl;
        }
    }
    // cout << "Find the number you want…" << endl;

}