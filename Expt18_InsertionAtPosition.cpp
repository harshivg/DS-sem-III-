#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class doublyNode{
    public:
    int data;
    doublyNode *next;
    doublyNode * prev;
    doublyNode(int a):data(a),next(nullptr),prev(nullptr){}
};

void insertAtStart(ListNode*& head, int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node; 
}

void insertAtEnd(ListNode* head, int val) {
    ListNode* temp = head;

    while (temp->next) {
        temp = temp->next;
    }

    ListNode* node = new ListNode(val);

    temp->next = node;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


void insertAtPosition(ListNode*& head, int data, int position) {
    ListNode* newNode = new ListNode(data);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        ListNode* current = head;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            cout << "Position exceeds the length of the linked list." << endl;
        }
    }
}


int main() {
    ListNode* head = new ListNode(5);

    // Insert nodes at the start and end.
    print(head);
    insertAtStart(head, 6);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);
    insertAtStart(head, 6);
    print(head);
    // Delete nodes from the start and end.
    insertAtPosition(head, 3, 0);
    insertAtPosition(head, 5, 1);

    print(head);

    return 0;
}