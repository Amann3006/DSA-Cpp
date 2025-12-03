#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

// print list
void print(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- ITERATIVE APPROACH --------------------
node* reverseLL(node* head){
    node* prev = NULL;
    node* curr = head;
    node* nxt = NULL;

    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

node* addOneIterative(node* head){
    head = reverseLL(head);

    node* temp = head;
    int carry = 1;

    while(temp){
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if(carry == 0) break;

        if(temp->next == NULL && carry){
            temp->next = new node(0);
        }
        temp = temp->next;
    }

    return reverseLL(head);
}

// -------------------- RECURSIVE APPROACH --------------------
int addCarry(node* head){
    if(head == NULL) return 1; // carry 1 (add one)

    int carry = addCarry(head->next);

    int sum = head->data + carry;
    head->data = sum % 10;

    return sum / 10;
}

node* addOneRecursive(node* head){
    int carry = addCarry(head);

    // If extra carry remains, add new node at front
    if(carry){
        node* newHead = new node(carry);
        newHead->next = head;
        return newHead;
    }

    return head;
}

// -------------------- MAIN --------------------
int main() {
    node* head = new node(9);
    head->next = new node(9);
    head->next->next = new node(8);
    head->next->next->next = new node(9);

    cout << "Original: ";
    print(head);

    cout << "After adding 1 (Iterative): ";
    head = addOneIterative(head);
    print(head);

    // recreate list for recursion example
    head = new node(9);
    head->next = new node(9);
    head->next->next = new node(8);
    head->next->next->next = new node(9);

    cout << "After adding 1 (Recursive): ";
    head = addOneRecursive(head);
    print(head);

    return 0;
}
