#include <bits/stdc++.h>
using namespace std;

// this structure defines a node in the binary tree
struct node {
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class solution {
public:
    vector<vector<int>> findvertical(node* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<node*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            node* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(temp->data);

            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

void printresult(const vector<vector<int>>& result) {
    for (auto level : result) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(10);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    root->right = new node(3);
    root->right->right = new node(10);
    root->right->left = new node(9);

    solution solution;

    vector<vector<int>> verticaltraversal = solution.findvertical(root);

    cout << "vertical traversal:" << endl;
    printresult(verticaltraversal);

    return 0;
}