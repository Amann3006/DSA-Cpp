#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};


bool check(node* root) {
    if (root == NULL) return 0;

    int left = check(root->left);
    int right = check(root->right);

    if(abs(left-right>1)){
        return false;
    }
    bool l = check(root->left);
    bool r = check(root->right);

    if(!l || !r){
        return false;
    }
    return true;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

   
    if(check(root)){
       cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
    

}