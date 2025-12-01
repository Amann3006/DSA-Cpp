#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

node* convert(vector<int>& arr){
    if(arr.size()==0) return NULL;
    node* head = new node(arr[0]);
    node* temp = head;
    for(int i=1;i<arr.size();i++){
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void print(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

node* sortNaive(node* head){
    vector<int> arr;
    node* temp = head;
    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i=0;
    while(temp){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}

node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeLists(node* a, node* b){
    node* dummy = new node(-1);
    node* temp = dummy;

    while(a && b){
        if(a->data < b->data){
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if(a) temp->next = a;
    else temp->next = b;

    return dummy->next;
}

node* sortOptimal(node* head){
    if(!head || !head->next) return head;
    node* mid = findMid(head);
    node* right = mid->next;
    mid->next = NULL;

    node* leftSorted = sortOptimal(head);
    node* rightSorted = sortOptimal(right);

    return mergeLists(leftSorted, rightSorted);
}

int main(){
    vector<int> arr = {5,1,4,2,3};
    node* head1 = convert(arr);
    node* head2 = convert(arr);

    head1 = sortNaive(head1);
    head2 = sortOptimal(head2);

    print(head1); cout << endl;
    print(head2); cout << endl;
}
