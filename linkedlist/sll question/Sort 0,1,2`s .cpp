#include <bits/stdc++.h>
using namespace std;

class node{
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
    cout << endl;
}

node* sort012_count(node* head){
    int c0=0, c1=0, c2=0;
    node* temp=head;

    while(temp){
        if(temp->data==0) c0++;
        else if(temp->data==1) c1++;
        else c2++;
        temp=temp->next;
    }

    temp=head;
    while(temp){
        if(c0){
            temp->data=0;
            c0--;
        } else if(c1){
            temp->data=1;
            c1--;
        } else {
            temp->data=2;
            c2--;
        }
        temp=temp->next;
    }
    return head;
}

node* sort012_optimal(node* head){
    node* zeroH = new node(-1);
    node* oneH  = new node(-1);
    node* twoH  = new node(-1);

    node* zeroT = zeroH;
    node* oneT  = oneH;
    node* twoT  = twoH;

    node* temp = head;

    while(temp){
        if(temp->data == 0){
            zeroT->next = temp;
            zeroT = temp;
        }
        else if(temp->data == 1){
            oneT->next = temp;
            oneT = temp;
        }
        else{
            twoT->next = temp;
            twoT = temp;
        }
        temp = temp->next;
    }

    twoT->next = NULL;

    if(oneH->next){
        zeroT->next = oneH->next;
        oneT->next = twoH->next;
    } else {
        zeroT->next = twoH->next;
    }

    node* newHead = zeroH->next;

    delete zeroH;
    delete oneH;
    delete twoH;

    return newHead;
}

int main(){
    vector<int> arr = {2,1,0,2,1,1,0,2};

    node* head1 = convert(arr);
    node* head2 = convert(arr);

    head1 = sort012_count(head1);
    head2 = sort012_optimal(head2);

    print(head1);
    print(head2);
}
