//Program: AVL Tree Implementation in C++
   

#include <iostream>
using namespace std;

// AVL Tree Node structure
struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
};

// Function to get height of a node
int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Utility function to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;  // new node is initially at height 1
    return node;
}

// Right Rotation (LL Case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left Rotation (RR Case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node
int getBalance(Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Recursive AVL Insertion
Node* insert(Node* node, int data) {
    // Standard BST insertion
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;  // Duplicate data not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Balancing Cases
    // LL Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Balanced node
}

// Preorder Traversal
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Main to test AVL Tree
int main() {
    Node* root = NULL;

    // Inserting values to create imbalanced tree and test balancing
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3); // RR Rotation
    root = insert(root, 4);
    root = insert(root, 5); // RR Rotation
    root = insert(root, 6); // RR Rotation

    cout << "Preorder traversal of the constructed AVL tree is: ";
    preOrder(root);
    cout << endl;

    return 0;
}
