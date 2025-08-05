// C++ program to implement an auto-completion system using an AVL Tree

#include <iostream>
#include <string>
using namespace std;

struct AVLNode {
    string word;
    int frequency;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int height(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* newNode(string word, int frequency) {
    AVLNode* node = new AVLNode();
    node->word = word;
    node->frequency = frequency;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* subtreeRootRight = x->right;

    x->right = y;
    y->left = subtreeRootRight;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* subtreeRootLeft = y->left;

    y->left = x;
    x->right = subtreeRootLeft;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

AVLNode* insert(AVLNode* node, string word, int frequency) {
    if (node == NULL)
        return newNode(word, frequency);

    if (word < node->word)
        node->left = insert(node->left, word, frequency);
    else if (word > node->word)
        node->right = insert(node->right, word, frequency);
    else
        node->frequency += frequency;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && word < node->left->word)
        return rightRotate(node);
    if (balance < -1 && word > node->right->word)
        return leftRotate(node);
    if (balance > 1 && word > node->left->word) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && word < node->right->word) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void traverseAndPrint(AVLNode* root, const string& prefix) {
    if (root == NULL)
        return;

    if (root->word.compare(0, prefix.length(), prefix) == 0)
        cout << root->word << " (Frequency: " << root->frequency << ")" << endl;

    traverseAndPrint(root->left, prefix);
    traverseAndPrint(root->right, prefix);
}

int main() {
    AVLNode* root = NULL;

    // Sample dictionary (word, frequency)
    root = insert(root, "car", 10);
    root = insert(root, "calendar", 5);
    root = insert(root, "cat", 8);
    root = insert(root, "camel", 3);
    root = insert(root, "candy", 6);
    root = insert(root, "camp", 4);

    string prefix;
    cout << "Enter word prefix: ";
    cin >> prefix;

    cout << "\nSuggestions:\n";
    traverseAndPrint(root, prefix);

    return 0;
}
