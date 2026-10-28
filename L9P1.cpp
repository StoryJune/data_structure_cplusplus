/*
Lab 9
Problem 1
CS 008 - Jason Li
*/

/*
Implementations: 

-display pre, in, and postorder of the tree. 
-able to find the height and size(# of nodes) of the tree. 

NOTE: 
-do not count nodes while traversing through the txt file
*/

#include <iostream>
#include <fstream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    
    TreeNode(int d, TreeNode* lc, TreeNode* rc) {
        data = d;
        lchild = lc;
        rchild = rc;
    }
};


int main(){
    string fileName;

    cout << "Enter filename : " << endl;
    cin >> fileName;

    fstream file(fileName);


}