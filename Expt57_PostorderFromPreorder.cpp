#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRootIdx = inMap[rootVal];
    int leftSubtreeSize = inRootIdx - inStart;

    root->left = buildTreeFromPreIn(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, inRootIdx - 1, inMap);
    root->right = buildTreeFromPreIn(preorder, inorder, preStart + leftSubtreeSize + 1, preEnd, inRootIdx + 1, inEnd, inMap);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 9, 12};
    vector<int> inorder = {1, 5, 7, 8, 9, 10, 12};

    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    TreeNode* root = buildTreeFromPreIn(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

