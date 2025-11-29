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

// -------------------------------------
// 1. Naive Method (Using Hash Set)
// -------------------------------------
node* findStartNaive(node* head) {
    unordered_set<node*> visited;

    node* temp = head;
    while(temp != NULL) {
        if(visited.find(temp) != visited.end())
            return temp; // First repeated node = start of loop

        visited.insert(temp);
        temp = temp->next;
    }
    return NULL; // No loop
}

// -------------------------------------
// 2. Optimal Method (Floyd's Algorithm)
// -------------------------------------
node* findStartOptimal(node* head) {
    node* slow = head;
    node* fast = head;

    // Step 1: Detect loop
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    // No loop
    if(fast == NULL || fast->next == NULL)
        return NULL;

    // Step 2: Move slow to head, keep fast where they met
    slow = head;

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Start of loop
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

    // Creating loop manually (5 -> 3)
    head->next->next->next->next = head->next->next;  

    node* start1 = findStartNaive(head);
    node* start2 = findStartOptimal(head);

    cout << "Naive Start of Loop: ";
    if(start1) cout << start1->data << endl;
    else cout << "No Loop\n";

    cout << "Optimal Start of Loop: ";
    if(start2) cout << start2->data << endl;
    else cout << "No Loop\n";

    return 0;
}
