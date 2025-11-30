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
    node* t = head;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

node* convert(vector<int>& arr){
    if(arr.empty()) return NULL;
    node* head = new node(arr[0]);
    node* t = head;
    for(int i=1;i<arr.size();i++){
        t->next = new node(arr[i]);
        t = t->next;
    }
    return head;
}

node* oddEvenIndexNaive(node* head){
    vector<int> odd, even;
    node* t = head;
    int idx = 1;

    while(t){
        if(idx % 2 != 0) odd.push_back(t->data);
        else even.push_back(t->data);
        t = t->next;
        idx++;
    }

    vector<int> merge = odd;
    merge.insert(merge.end(), even.begin(), even.end());
    return convert(merge);
}

node* oddEvenIndexOptimal(node* head){
    if(!head || !head->next) return head;

    node* oddH = head;
    node* evenH = head->next;

    node* odd = oddH;
    node* even = evenH;

    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenH;
    return oddH;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    node* head = convert(arr);

    print(head);

    node* a = oddEvenIndexNaive(head);
    print(a);

    node* b = oddEvenIndexOptimal(head);
    print(b);

    return 0;
}
