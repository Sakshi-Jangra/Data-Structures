/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<limits.h>

using namespace std;

// Node Structure
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int a){
        data = a;
        this->left = NULL;
        this->right = NULL;
    }
};


// returns number of BST and if subtree is BST or not
void NumberOfBST(struct Node* root, int& num_BST, bool& isBST, int& _min, int& _max){
    // NO Node , no traversal
    if(root == NULL)
        return;

    // Leaf Nodes
    if(root->left == NULL && root->right == NULL){
        isBST = true;
        _min = root->data;
        _max = root->data;
        num_BST++;
        return;
    }

    // variable for traversal
    int L_min = INT_MAX, R_min = INT_MAX;
    int L_max = INT_MIN, R_max = INT_MIN;;

    // Left side traversal
    if(root->left != NULL){
        NumberOfBST(root->left, num_BST, isBST, _min, _max);
        L_min = _min;
        L_max = _max;

    }

    // right side traversal
    if(root->right != NULL){
        NumberOfBST(root->right, num_BST, isBST, _min, _max);
        R_min = _min;
        R_max = _max;
    }


    // update min and max of subtree
    _min = min(root->data, (min(L_min, R_min)));
    _max = max(root->data, (max(L_max, R_max)));

    if(root->data > L_max && root->data < R_min){
        if(isBST)
            num_BST++;
    }
    else
        isBST = false;

    return;
}

int main()
{
    // root
    struct Node* root = new Node(5);
    int num_BST = 0;
    bool isBST = false;
    int _min = INT_MAX;
    int _max = INT_MIN;

    // make Binary tree
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->right->right = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(7);

    NumberOfBST(root,num_BST,isBST, _min, _max);
    cout<<num_BST;

    return 0;
}
