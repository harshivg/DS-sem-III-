#include <iostream>

using namespace std;

class Queue {
private:
    int* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        array = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to add an element to the back of the queue (enqueue)
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    // Function to remove and return the element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value
        }
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    // Function to get the element at the front of the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Return a sentinel value
        }
        return array[front];
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    cout << "Dequeue operation performed." << endl;

    cout << "Front element after dequeue: " << queue.peek() << endl;

    return 0;
}
