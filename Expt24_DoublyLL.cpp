#include <iostream>

using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the beginning of the doubly linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a new node at the end of the doubly linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to delete a node with a specific value from the doubly linked list
    void deleteNode(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to display the doubly linked list from head to tail
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to display the doubly linked list from tail to head
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList doublyList;

    doublyList.insertAtBeginning(3);
    doublyList.insertAtBeginning(2);
    doublyList.insertAtBeginning(1);

    doublyList.insertAtEnd(4);

    cout << "Doubly Linked List (Forward):" << endl;
    doublyList.displayForward();

    cout << "Doubly Linked List (Backward):" << endl;
    doublyList.displayBackward();

    doublyList.deleteNode(2);

    cout << "Doubly Linked List after deleting 2:" << endl;
    doublyList.displayForward();

    return 0;
}
