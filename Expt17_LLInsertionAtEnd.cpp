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


void deletefromStart(ListNode*& head) {
    if (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


void deleteFromEnd(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return;
    }

    ListNode* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
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
    deletefromStart(head);
    deleteFromEnd(head);

    print(head);

    return 0;
}