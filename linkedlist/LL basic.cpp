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

    for(int i=1; i<arr.size(); i++){
        node*temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}


// find leng of ll
int lengofll(node*head){
 int cnt=0;
  node*temp=head;
  while(temp!=nullptr){
          temp=temp->next;
          cnt++;
    }
    return cnt;
}

//tocheckelement
int checkelement(node*head,int val){
        node*temp=head;

    while(temp!=nullptr){
          if(temp->data==val){
            return 1;
          }
          temp=temp->next;
    }
    return 0;
}

int main(){
    vector<int>arr={2,5,6,7,9};
   // node* x=new node(arr[0]);
    node*head=convert(arr);
    node*temp=head;
    cout<<endl<<lengofll(head);
    cout<<endl<<checkelement(head,5);
}