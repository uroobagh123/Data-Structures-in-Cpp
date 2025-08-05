// This program searches for a node in a BST and prints the subtree rooted at that node.

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        } else if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    int target1 = 2;
    TreeNode* result1 = solution.searchBST(root1, target1);
    cout << "Example 1 output:\n";
    printTree(result1);
    cout << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    int target2 = 5;
    TreeNode* result2 = solution.searchBST(root2, target2);
    cout << "Example 2 output:\n";
    printTree(result2); // This will print nothing if node not found
    cout << endl;

    return 0;
}
