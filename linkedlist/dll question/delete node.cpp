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
//deletehead
node*deletehead(node*head){

    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    node*temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete(temp);
    return head;
}

//deletetail
node*deletetail(node*head){

    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    
    node*temp=head;

    while(temp->next!=nullptr){
        
        temp=temp->next;
    }
    //last node prev is second last node
    node*back=temp->prev;
    temp->prev=nullptr;
    back->next=nullptr;
    delete(temp);

    return head;
}

//delete kth element
node*deletekth(node*head,int k){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    int cnt=0; node*temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    node*back=temp->prev;
    node*nextnode =temp->next;
    
    if(back==nullptr && nextnode==nullptr){
        delete (temp);
        return nullptr;
    }
    else if(back==nullptr){
       return deletehead(head);
       
    }
    else if(nextnode==nullptr){
        return deletetail(head);
    }
    back->next=nextnode;
    nextnode->prev=back;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete(temp);
    return head;
}
//delete val node
node*deleteval(node*head,int val){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    node*temp=head;
    while(temp!=nullptr){
        
        if(temp->data==val){
            break;
        }
        temp=temp->next;
    }
    node*back=temp->prev;
    node*nextnode =temp->next;
    
    if(back==nullptr && nextnode==nullptr){
        delete (temp);
        return nullptr;
    }
    else if(back==nullptr){
       return deletehead(head);
       
    }
    else if(nextnode==nullptr){
        return deletetail(head);
    }
    back->next=nextnode;
    nextnode->prev=back;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete(temp);
    return head;
}

int main(){
    vector<int>arr={2,5,6,7,9};

    node*head=convert(arr);
   // print(head);
  // head=deletehead(head);
  // head=deletetail(head);
 // head=deletekth(head,2);
 head=deleteval(head,9);
    print(head);


   return 0;
}