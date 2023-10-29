#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(vector<int>& v){for(int i : v){cout<<i<<" ";}cout<<endl;}

void preorder(vector<int>& ans, TreeNode* root){
    if(root==NULL) return;

    ans.push_back(root-> val);
    preorder(ans, root->left);
    preorder(ans, root->right);

}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(ans, root);
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    vector<int> Preorder = preorderTraversal(root);
    print(Preorder);
}