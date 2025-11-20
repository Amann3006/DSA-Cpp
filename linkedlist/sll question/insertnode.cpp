#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int data1){
        data=data1;
       next=nullptr;
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
//arr to ll
node*convert(vector<int>&arr){
    node* head=new node(arr[0]);
    node*mover=head;
    int n=arr.size();

    for(int i=1; i<n;i++){
        node*temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//insert at head

node*inserthead(node*head,int val){
    node*newnode=new node(val);

    newnode->next=head;

    return newnode;
}

//insert at tail
node*insertattail(node*head,int val){
    node*newnode=new node(val);

    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;

    return head;
}

node*insertatk(node*head,int k,int val)
{
  if(head==nullptr){
    return new node(val);
  }

  if(k==1){
    node*newnode=new node(val);
    newnode->next=head;

    return newnode;
  }

  int cnt=0;
  node*prev=nullptr;
  node*temp=head;
  node*newnode=new node(val);
  while(temp->next!=nullptr){
     cnt++;
     if(cnt==k){
        prev->next=newnode;
        newnode->next=temp;
        return head;
     }
     prev=temp;
     temp=temp->next;

  }
  return head;
}
int main(){
    vector<int>arr={2,5,6,7,9};
  
    node*head=convert(arr);
 //  head=inserthead(head,8);
 //    head=insertattail(head,8);
  head=insertatk(head,3,8);
     print(head);
}