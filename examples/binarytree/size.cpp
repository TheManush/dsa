// C++ program to find the size
// of a binary tree.
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to find the 
// size of binary tree.
int getSize(Node* root) {
    if (root == nullptr)
        return 0;
    
    // Find the size of left and right 
    // subtree.
    int left = getSize(root->left);
    int right = getSize(root->right);
    
    // return the size of curr subtree.
    return left+right+1;
}

int main() {

    // Constructed binary tree is
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << getSize(root) << endl;

    return 0;
}
