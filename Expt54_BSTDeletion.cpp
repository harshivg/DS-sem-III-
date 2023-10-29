#include <iostream>

using namespace std;

// Define the structure for a node in the Binary Search Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum node in a BST
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Function to delete a node in a BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the in-order successor's content to this node
        root->val = temp->val;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->val);
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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Before Deletion: ";
    inorderTraversal(root);
    cout << endl;

    int keyToDelete = 3;
    root = deleteNode(root, keyToDelete);

    cout << "After Deletion of " << keyToDelete << ": ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
