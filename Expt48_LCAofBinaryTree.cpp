#include <iostream>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the LCA of two nodes in a binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) {
        return root;
    } else if (leftLCA) {
        return leftLCA;
    } else {
        return rightLCA;
    }
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;

    return 0;
}
