#include <bits/stdc++.h>

using namespace std;

// Define the structure for a node in the Binary Search Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to construct a BST from its postorder traversal
TreeNode* constructBST(vector<int>& postorder, int& index, int minValue) {
    if (index < 0 || postorder[index] < minValue) {
        return nullptr;
    }

    // Create the root node
    TreeNode* root = new TreeNode(postorder[index--]);

    // Recursively construct the right subtree with a minimum value constraint
    root->right = constructBST(postorder, index, root->val);

    // Recursively construct the left subtree with the minimum value of the root
    root->left = constructBST(postorder, index, minValue);

    return root;
}

// Function to construct a BST from its postorder traversal
TreeNode* constructBSTFromPostorder(vector<int>& postorder) {
    int index = postorder.size() - 1;
    return constructBST(postorder, index, INT_MIN);
}

// Function to perform a preorder traversal of the Binary Search Tree
void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    vector<int> postorder = {1, 3, 2, 6, 5, 8, 7, 4};

    TreeNode* root = constructBSTFromPostorder(postorder);

    cout << "Preorder Traversal of the Binary Search Tree: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
