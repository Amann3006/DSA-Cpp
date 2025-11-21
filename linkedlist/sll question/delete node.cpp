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

//delete head 
node*removehead(node*head){
    node*temp=head;
    head=head->next;

    delete(temp);
    return head;
}

//delete tail
node*removetail(node*head){
    
    node*temp=head;

    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}
//delete kth element 
node*removekth(node*head,int k){
    if(head==nullptr){
        return nullptr;
    }

    if(k==1){
        node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=0; 
    node*temp=head;
    node*prev=NULL;
    while(temp!=nullptr){
        cnt++;
        if(k==cnt){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//delete value given 
node*removeval(node*head,int val){
    if(head==nullptr){
        return nullptr;
    }

    if(head->data==val){
        node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    
    node*temp=head;
    node*prev=NULL;
    while(temp!=nullptr){
        
        if(temp->data==val){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={2,5,6,7,9};
  
    node*head=convert(arr);
   // head=removehead(head);

   // print(head);
    //head=removetail(head);
   // print(head);
   head=removeval(head,5);
   print(head);
}