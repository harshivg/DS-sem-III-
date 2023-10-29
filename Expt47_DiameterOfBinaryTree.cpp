#include <bits/stdc++.h>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};


int solve(TreeNode* root, int& res){
        if(root == nullptr) return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = 1 + max(l,r);
        int ans = 1 + l + r;
        res = max(res, ans);

        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res-1;
    }

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree is: " << diameter << endl;

    return 0;
}
