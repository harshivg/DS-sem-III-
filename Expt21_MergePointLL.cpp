#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the merge point of two linked lists
Node* findMergePoint(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;

    // Traverse both lists
    while (current1 != current2) {
        if (current1 == nullptr) {
            current1 = head2; // Adjust the pointer for the first list
        } else {
            current1 = current1->next;
        }

        if (current2 == nullptr) {
            current2 = head1; // Adjust the pointer for the second list
        } else {
            current2 = current2->next;
        }
    }

    return current1; // Found the merge point
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
    Node* commonNode = new Node(7);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = commonNode;

    Node* head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    head2->next->next->next = commonNode; // Merge point

    cout << "Linked List 1:" << endl;
    printList(head1);

    cout << "Linked List 2:" << endl;
    printList(head2);

    Node* mergePoint = findMergePoint(head1, head2);
    if (mergePoint != nullptr) {
        cout << "Merge Point: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
