#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the bottom view of a binary tree
void bottomView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Create a queue for level-order traversal
    queue<pair<TreeNode*, int>> q;

    // Create a map to store nodes at each horizontal distance
    map<int, int> bottomViewMap;

    // Initialize the root node and horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Update the node for the current horizontal distance
        bottomViewMap[hd] = node->val;

        // Enqueue the left and right child nodes with adjusted horizontal distances
        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the nodes in the bottom view
    for (const auto& pair : bottomViewMap) {
        cout << pair.second << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Bottom View of the binary tree: ";
    bottomView(root);
    cout << endl;

    return 0;
}
