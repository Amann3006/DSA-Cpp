#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = nullptr;
    }
};

vector<int> preordertraversal(node* root){
    vector<int> pre;
    if(root == nullptr) return pre;

    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node* curr = st.top();
        st.pop();

        pre.push_back(curr->data);

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }

    return pre;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    vector<int> ans = preordertraversal(root);

    for(auto i : ans) cout << i << " ";
}