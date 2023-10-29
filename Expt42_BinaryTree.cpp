#include <iostream>

using namespace std;

// Define the structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a new node into the binary tree
    Node* insert(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Function to perform an inorder traversal of the binary tree
    void inorderTraversal(Node* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}
