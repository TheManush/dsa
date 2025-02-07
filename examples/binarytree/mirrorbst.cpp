#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to build the new BST with the desired properties
Node* buildNewBST(Node* originalRoot) {
    if (originalRoot == nullptr) {
        return nullptr;
    }

    // Create a new node with the same value as the original node
    Node* newNode = new Node(originalRoot->data);

    // Recursively build the left subtree of the new node using the right subtree of the original node
    newNode->left = buildNewBST(originalRoot->right);

    // Recursively build the right subtree of the new node using the left subtree of the original node
    newNode->right = buildNewBST(originalRoot->left);

    return newNode;
}

// Function to print the BST (in-order traversal)
void printBST(Node* root) {
    if (root == nullptr) {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    // Original BST
    Node* originalRoot = nullptr;
    originalRoot = insert(originalRoot, 50);
    originalRoot = insert(originalRoot, 30);
    originalRoot = insert(originalRoot, 70);
    originalRoot = insert(originalRoot, 20);
    originalRoot = insert(originalRoot, 40);
    originalRoot = insert(originalRoot, 60);
    originalRoot = insert(originalRoot, 80);

    // Build the new BST with the desired properties
    Node* newRoot = buildNewBST(originalRoot);

    // Print the new BST (in-order traversal to verify)
    cout << "New BST (in-order traversal): ";
    printBST(newRoot);
    cout << endl;

    return 0;
}
