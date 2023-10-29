#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect and remove a cycle in a linked list
bool detectAndRemoveCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Phase 1: Detect the cycle using the tortoise and hare algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            break;
        }
    }

    if (slow != fast) {
        // No cycle found
        return false;
    }

    // Phase 2: Remove the cycle by finding the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // At this point, slow and fast are at the start of the cycle
    fast = fast->next; // Move fast one step ahead

    while (fast->next != slow) {
        fast = fast->next;
    }

    // Remove the cycle by breaking the link
    fast->next = nullptr;

    return true;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a cycle by connecting the last node to the second node
    head->next->next->next->next->next = head->next;

    bool hasCycle = detectAndRemoveCycle(head);

    if (hasCycle) {
        cout << "Cycle detected and removed:" << endl;
        printList(head);
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
