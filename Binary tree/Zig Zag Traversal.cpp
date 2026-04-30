#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                node* curr = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                level[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    cout << "[";
    for (auto &level : ans) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i != level.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}