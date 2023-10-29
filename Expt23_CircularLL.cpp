#include <iostream>

using namespace std;

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the circular linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            newNode->next = newNode; // Create a self-loop for the first node
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    // Function to insert a new node at the end of the circular linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            newNode->next = newNode; // Create a self-loop for the first node
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // Function to delete a node with a specific value from the circular linked list
    void deleteNode(int value) {
        if (head == nullptr) {
            return; // List is empty
        }

        if (head->data == value) {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = head->next; // Update the head
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            while (current->next != head) {
                if (current->next->data == value) {
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "Head" << endl;
    }
};

int main() {
    CircularLinkedList circularList;

    circularList.insertAtBeginning(3);
    circularList.insertAtBeginning(2);
    circularList.insertAtBeginning(1);

    circularList.insertAtEnd(4);

    cout << "Circular Linked List:" << endl;
    circularList.display();

    circularList.deleteNode(2);

    cout << "Circular Linked List after deleting 2:" << endl;
    circularList.display();

    return 0;
}