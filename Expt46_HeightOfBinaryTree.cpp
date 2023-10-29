#include <iostream>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of a binary tree
int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is 0
    }

    // Calculate the height of the left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the maximum height plus 1 (for the current node)
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = getHeight(root);

    cout << "Height of the binary tree is: " << height << endl;

    return 0;
}
