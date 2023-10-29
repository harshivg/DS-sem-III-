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


void postorder(vector<int>& ans, TreeNode* root){
    if(root==NULL) return;

    postorder(ans, root->left);
    postorder(ans, root->right);
    ans.push_back(root-> val);

}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorder(ans, root);
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    vector<int> PostOrder = postorderTraversal(root);
    print(PostOrder);
}