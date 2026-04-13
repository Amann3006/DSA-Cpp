#include <iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(node*root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    inorder(root);

}