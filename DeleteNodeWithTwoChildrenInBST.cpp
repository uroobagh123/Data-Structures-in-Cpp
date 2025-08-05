// Program to delete a node (including with two children) from a Binary Search Tree while maintaining BST properties

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* successor = root->right;
        while (successor && successor->left != NULL)
            successor = successor->left;

        root->val = successor->val; // Copy inorder successor’s value to this node
        root->right = deleteNode(root->right, successor->val); // Delete the inorder successor
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 20); // deleting leaf
    cout << "Inorder traversal after deleting leaf node (20): ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 70); // deleting node with one child
    cout << "Inorder traversal after deleting node with one child (70): ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 30); // deleting node with two children
    cout << "Inorder traversal after deleting node with two children (30): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
