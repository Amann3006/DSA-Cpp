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

vector<vector<int>> bfs(node* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        while(size--){
            node* temp = q.front();
            q.pop();

            level.push_back(temp->data);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        ans.push_back(level);
    }

    return ans;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    vector<vector<int>> res = bfs(root);

    // print result
    for(auto &level : res){
        for(int x : level) cout << x << " ";
        cout << endl;
    }
}