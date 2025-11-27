#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    }
};

node* reverseNaive(node* head) {
    if(!head) return NULL;

    vector<int> arr;
    node* temp = head;

    // Step 1: Store all values in vector
    while(temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;
    int i = arr.size() - 1;

    // Step 2: Reassign values in reverse order
    while(temp != NULL) {
        temp->data = arr[i--];
        temp = temp->next;
    }

    return head;
}

node* reverseRecursive(node* head) {
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse rest of the list
    node* newHead = reverseRecursive(head->next);

    // Fix current node
    head->next->next = head;
    head->next = NULL;

    return newHead;  // New head of reversed list
}


node* reverseOptimal(node* head) {
    node* prev = NULL;
    node* curr = head;

    while(curr != NULL) {
        node* nextNode = curr->next; // store next
        curr->next = prev;           // reverse link
        prev = curr;                 // move prev forward
        curr = nextNode;             // move curr forward
    }

    return prev; // new head
}


void printLL(node* head) {
    node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


node* convert(vector<int>& arr) {
    if(arr.size() == 0) return NULL;

    node* head = new node(arr[0]);
    node* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    node* head = convert(arr);

    cout << "Original: ";
    printLL(head);

    // Naive reverse
    head = reverseNaive(head);
    cout << "Naive Reverse: ";
    printLL(head);

    // Optimal reverse
    head = reverseOptimal(head);
    cout << "Optimal Reverse: ";
    printLL(head);

    
head = reverseRecursive(head);

cout << "Recursive Reverse: ";
printLL(head);


    return 0;
}
