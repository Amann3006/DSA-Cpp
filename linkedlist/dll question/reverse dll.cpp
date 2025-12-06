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
          cout<<temp->data;
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
//reverse
node*reversedll(node*head){
    node*last=nullptr;
    node*curr=head;
    
    while(curr!=nullptr){
        last=curr->prev;
        curr->prev=curr->next;
        curr->next=last;

        curr=curr->prev;
    }
    return last->prev;
}

int main(){
    vector<int>arr={2,5,6,7,9};

    node*head=convert(arr);
    head=reversedll(head);
    print(head);


   return 0;
}