// Program to perform various operations on a Binary Search Tree (BST)

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// BST class definition
class BST {
private:
    Node* root;

    Node* insertNodeHelper(Node* root, int value) {
        if (root == NULL)
            return new Node(value);
        if (value < root->data)
            root->left = insertNodeHelper(root->left, value);
        else if (value > root->data)
            root->right = insertNodeHelper(root->right, value);
        return root;
    }

    void inorderTraversalHelper(Node* root) {
        if (root == NULL) return;
        inorderTraversalHelper(root->left);
        cout << root->data << " ";
        inorderTraversalHelper(root->right);
    }

    void preorderTraversalHelper(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorderTraversalHelper(root->left);
        preorderTraversalHelper(root->right);
    }

    void postorderTraversalHelper(Node* root) {
        if (root == NULL) return;
        postorderTraversalHelper(root->left);
        postorderTraversalHelper(root->right);
        cout << root->data << " ";
    }

    int findSmallestHelper(Node* root) {
        if (root == NULL) return -1;
        if (root->left == NULL) return root->data;
        return findSmallestHelper(root->left);
    }

    int countNodesHelper(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodesHelper(root->left) + countNodesHelper(root->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insertNode(int value) {
        root = insertNodeHelper(root, value);
    }

    void inorderTraversal() {
        cout << "In-order Traversal: ";
        inorderTraversalHelper(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Pre-order Traversal: ";
        preorderTraversalHelper(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Post-order Traversal: ";
        postorderTraversalHelper(root);
        cout << endl;
    }

    int findSmallest() {
        return findSmallestHelper(root);
    }

    int countNodes() {
        return countNodesHelper(root);
    }
};

// Main function to demonstrate BST operations
int main() {
    BST bst;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert node\n";
        cout << "2. In-order traversal\n";
        cout << "3. Pre-order traversal\n";
        cout << "4. Post-order traversal\n";
        cout << "5. Find the smallest value\n";
        cout << "6. Count the nodes\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insertNode(value);
                break;
            case 2:
                bst.inorderTraversal();
                break;
            case 3:
                bst.preorderTraversal();
                break;
            case 4:
                bst.postorderTraversal();
                break;
            case 5:
                cout << "Smallest value: " << bst.findSmallest() << endl;
                break;
            case 6:
                cout << "Number of nodes: " << bst.countNodes() << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Enter a number between 1 and 7." << endl;
        }
    } while (choice != 7);

    return 0;
}
