#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int d){
        data = d;
        next = prev = NULL;
    }
};

//  Naive Approach (O(n²))
void findPairsNaive(node* head, int target){
    node* ptr1 = head;
    while(ptr1){
        node* ptr2 = ptr1->next;
        while(ptr2){
            if(ptr1->data + ptr2->data == target){
                cout << "(" << ptr1->data << ", " << ptr2->data << ")\n";
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

// Two Pointer Approach (O(n))
void findPairsTwoPointer(node* head, int target){
    if(!head) return;

    // Move to last node (tail)
    node* tail = head;
    while(tail->next) tail = tail->next;

    node* start = head;
    node* end = tail;

    while(start != end && end->next != start){
        int sum = start->data + end->data;

        if(sum == target){
            cout << "(" << start->data << ", " << end->data << ")\n";
            start = start->next;
            end = end->prev;
        }
        else if(sum < target){
            start = start->next;
        }
        else{
            end = end->prev;
        }
    }
}

int main(){
    // Create DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    node* head = new node(1);
    head->next = new node(2); head->next->prev = head;
    head->next->next = new node(3); head->next->next->prev = head->next;
    head->next->next->next = new node(4); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new node(5); head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new node(6); head->next->next->next->next->next->prev = head->next->next->next->next;

    int target = 7;

    cout << "Naive Approach:\n";
    findPairsNaive(head, target);

    cout << "\nTwo Pointer Approach:\n";
    findPairsTwoPointer(head, target);
}
