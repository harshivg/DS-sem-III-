#include <iostream>
#include <queue>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the right view of a binary tree
void rightView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Create a queue for level-order traversal
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Print the last node at each level (rightmost node)
            if (i == levelSize - 1) {
                cout << node->val << " ";
            }

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Right View of the binary tree: ";
    rightView(root);
    cout << endl;

    return 0;
}
