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

bool search(ListNode* head, int x){
    while(head){
        if(head->val == x) return true;
    }
    return false;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 0; i < 4; i++){
        temp->next = new ListNode(i); temp = temp->next;
    }

    cout<<search(head, 1)<<endl; print(head);
}