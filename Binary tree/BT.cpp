#include <bits/stdc++.h>
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

node* buildTree() {
    int x;
    cin >> x;

    if (x == -1) return NULL;

    node* root = new node(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    cout << "Enter tree (-1 for NULL): ";
    node* root = buildTree();
}