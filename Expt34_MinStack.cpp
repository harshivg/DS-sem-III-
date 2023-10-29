#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    // Get the top element from the stack
    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Return a sentinel value for an empty stack
    }

    // Get the minimum element from the stack
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Return a sentinel value for an empty stack
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(2);
    minStack.push(5);
    minStack.push(1);

    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "After popping the top element:" << endl;
    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    return 0;
}
