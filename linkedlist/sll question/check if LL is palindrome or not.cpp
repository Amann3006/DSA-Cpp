#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* convert(vector<int> &arr){
    if(arr.size() == 0) return NULL;

    node* head = new node(arr[0]);
    node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        mover->next = new node(arr[i]);
        mover = mover->next;
    }
    return head;
}

//naive 
bool isPalindromeNaive(node* head){
    vector<int> arr;
    node* temp = head;

    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0, j = arr.size() - 1;
    while(i < j){
        if(arr[i] != arr[j]) return false;
        i++;
        j--;
    }

    return true;
}

//optimal 
node* reverseList(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindromeOptimal(node* head){
    if(head == NULL || head->next == NULL) return true;

    node* slow = head;
    node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondHalf = reverseList(slow->next);

    node* first = head;
    node* second = secondHalf;

    bool isPalin = true;

    while(second != NULL){
        if(first->data != second->data){
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    slow->next = reverseList(secondHalf);

    return isPalin;
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 1};
    node* head = convert(arr);

    print(head);

    cout << (isPalindromeNaive(head) ? "YES" : "NO") << endl;
    cout << (isPalindromeOptimal(head) ? "YES" : "NO") << endl;

    return 0;
}
