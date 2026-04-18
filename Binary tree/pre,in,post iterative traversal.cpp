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

vector<int> inorderTraversal(node* root) {
    vector<int> in;
    stack<node*> st;
    node* curr = root;

    while (curr != NULL || !st.empty()) {
        // Go to leftmost node
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // Process node
        curr = st.top();
        st.pop();
        in.push_back(curr->data);

        // Move to right subtree
        curr = curr->right;
    }

    return in;
}

vector<int> postorderTraversal(node* root) {
    vector<int> post;
    if (root == NULL) return post;

    stack<node*> st;
    node* curr = root;
    node* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            node* temp = st.top();

            // if right child exists and not processed yet
            if (temp->right != NULL && lastVisited != temp->right) {
                curr = temp->right;
            } else {
                post.push_back(temp->data);
                lastVisited = temp;
                st.pop();
            }
        }
    }

    return post;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    vector<int> ans = preordertraversal(root);
    vector<int>ans1=inorderTraversal(root);
    vector<int>ans2=postorderTraversal(root);
    cout<<"preorder"<<endl;
    for(auto i : ans) cout << i << " ";
    cout<<endl<<"inorder"<<endl;
    for(auto i : ans1) cout << i << " ";
    cout<<endl<<"postorder"<<endl;
    for(auto i : ans2) cout << i << " ";
    
}