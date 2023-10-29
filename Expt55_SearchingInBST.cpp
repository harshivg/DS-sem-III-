#include <iostream>

using namespace std;

// Define the structure for a node in the Binary Search Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to search for a value in a BST
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }

    if (root->val == value) {
        return true; // Value found
    } else if (value < root->val) {
        return search(root->left, value); // Search in the left subtree
    } else {
        return search(root->right, value); // Search in the right subtree
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int target = 4;

    if (search(root, target)) {
        cout << target << " is found in the BST." << endl;
    } else {
        cout << target << " is not found in the BST." << endl;
    }

    return 0;
}
