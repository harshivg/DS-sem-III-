#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Define a binary expression tree node
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build a binary expression tree from a postfix expression
TreeNode* buildExpressionTree(string postfix) {
    stack<TreeNode*> st;

    for (char c : postfix) {
        if (!isOperator(c)) {
            TreeNode* node = new TreeNode(string(1, c));
            st.push(node);
        } else {
            TreeNode* rightOperand = st.top();
            st.pop();
            TreeNode* leftOperand = st.top();
            st.pop();

            TreeNode* operatorNode = new TreeNode(string(1, c));
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;
            st.push(operatorNode);
        }
    }

    return st.top();
}

// Function to perform an in-order traversal of the binary expression tree
void inOrderTraversal(TreeNode* root) {
    if (root) {
        if (isOperator(root->value[0]) && root != root) cout << "(";
        inOrderTraversal(root->left);
        cout << root->value;
        inOrderTraversal(root->right);
        if (isOperator(root->value[0]) && root != root) cout << ")";
    }
}

int main() {
    // Example postfix expression: "34*2+"
    string postfixExpression = "34*2+";

    TreeNode* expressionTree = buildExpressionTree(postfixExpression);

    cout << "Infix expression: ";
    inOrderTraversal(expressionTree);
    cout << endl;

    return 0;
}
