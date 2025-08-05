// Program to check if a given Binary Search Tree (BST) is an AVL Tree or not.

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Unable to allocate memory for new node" << endl;
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to compute the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to get absolute value
int abs(int x) {
    return (x < 0) ? -x : x;
}

// Function to check if the BST is AVL
bool isAVL(Node* root) {
    if (root == NULL) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isAVL(root->left) &&
        isAVL(root->right)) {
        return true;
    }

    return false;
}

// Main function
int main() {
    Node* root = NULL;
    int n, val;

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    cout << "Enter the nodes of the BST: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insertNode(root, val);
        if (!root) {
            cout << "Error inserting node" << endl;
            return 1;
        }
    }

    if (isAVL(root)) {
        cout << "AVL" << endl;
    } else {
        cout << "Not AVL" << endl;
    }

    return 0;
}
