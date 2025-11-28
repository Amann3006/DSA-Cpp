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


bool detectLoopNaive(node* head) {
    unordered_set<node*> visited;

    node* temp = head;
    while(temp != NULL) {
        if(visited.find(temp) != visited.end())
            return true; // loop found

        visited.insert(temp);
        temp = temp->next;
    }
    return false; // no loop
}

//optimal 
bool detectLoopOptimal(node* head) {
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps

        if(slow == fast)           // both meet → loop exists
            return true;
    }
    return false;
}


void printLL(node* head) {
    node* temp = head;
    int count = 0;

    while(temp != NULL && count < 20) { 
        cout << temp->data << " ";
        temp = temp->next;
        count++;
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

    // Create a loop manually for testing
    head->next->next->next->next = head->next; // 5 -> 2

    cout << "Naive Loop Detection: ";
    cout << (detectLoopNaive(head) ? "Loop Found" : "No Loop") << endl;

    cout << "Optimal Loop Detection: ";
    cout << (detectLoopOptimal(head) ? "Loop Found" : "No Loop") << endl;

    return 0;
}
