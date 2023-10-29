#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a sentinel value
        }
        return top->data;
    }

    // Function to display the elements in the stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack:" << endl;
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "After popping the top element:" << endl;
    stack.display();

    return 0;
}
