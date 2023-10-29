#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the back of the queue (enqueue)
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove and return the element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }
        return data;
    }

    // Function to get the element at the front of the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Return a sentinel value
        }
        return front->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    cout << "Dequeue operation performed." << endl;

    cout << "Front element after dequeue: " << queue.peek() << endl;

    return 0;
}
