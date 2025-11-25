#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data1){
        data=data1;
       next=nullptr;
       prev=nullptr;
    }
};
//print ll
void print(node*head){
    node*temp=head;
     while(temp!=nullptr){
          cout<<temp->data<<" ";
          temp=temp->next;
    }
}
//arr to dll
node*convert(vector<int>&arr){
    node* head=new node(arr[0]);
    node*mover=head;

    for(int i=1; i<arr.size(); i++){
        node*temp=new node(arr[i]);
        
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}
// insert at head
node* inserthead(node* head, int val){

    node* newNode = new node(val);

    newNode->next = head;

    if(head != nullptr){
        head->prev = newNode;
    }

    return newNode; // new node becomes head
}



// insert at tail
node* inserttail(node* head, int val){

    node* newNode = new node(val);

    if(head == nullptr){
        return newNode;
    }

    node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}



// insert at kth position (1-based index)
node* insertekth(node* head, int k, int val){

    if(k == 1){
        return inserthead(head, val);
    }

    int cnt = 1;
    node* temp = head;

    while(temp != nullptr && cnt < k-1){
        cnt++;
        temp = temp->next;
    }

    // if inserting at tail
    if(temp->next == nullptr){
        return inserttail(head, val);
    }

    node* newNode = new node(val);

    node* front = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    newNode->next = front;
    front->prev = newNode;

    return head;
}


int main(){
    vector<int> arr = {2,5,6,7,9};

    node* head = convert(arr);

    head = inserthead(head, 1);      // insert at beginning
    head = inserttail(head, 10);     // insert at end
    head = insertekth(head, 3, 99);  // insert 99 at 3rd position

    print(head);
    return 0;
}
