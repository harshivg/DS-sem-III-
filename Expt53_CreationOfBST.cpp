#include <iostream>

using namespace std;

// Define the structure for a node in the Binary Search Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the Binary Search Tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an inorder traversal of the Binary Search Tree
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the Binary Search Tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);

    cout << "Inorder Traversal of the Binary Search Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
