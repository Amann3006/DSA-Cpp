#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// delete all occurrences using nodenext & nodeprev variables
node* deleteOcc(node* head, int key){
    node* curr = head;

    while(curr != nullptr){

        node* nodenext = curr->next;   // temp next pointer
        node* nodeprev = curr->prev;   // temp prev pointer

        if(curr->data == key){

            // deleting head
            if(curr == head){
                head = nodenext;
                if(head) head->prev = nullptr;
            }
            else{
                nodeprev->next = nodenext;
                if(nodenext) nodenext->prev = nodeprev;
            }

            delete curr;
        }

        curr = nodenext;
    }

    return head;
}

void print(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    node* head = new node(1);
    head->next = new node(2); head->next->prev = head;
    head->next->next = new node(3); head->next->next->prev = head->next;
    head->next->next->next = new node(2); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new node(4); head->next->next->next->next->prev = head->next->next->next;

    int key = 2;
    head = deleteOcc(head, key);

    print(head);
}
