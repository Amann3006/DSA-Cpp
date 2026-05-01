#include <iostream>
#include <vector>
using namespace std;

// node structure
struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class solution {
public:
    bool isleaf(node* root) {
        return !root->left && !root->right;
    }

    void addleftboundary(node* root, vector<int>& res) {
        node* curr = root->left;
        while (curr) {
            if (!isleaf(curr)) {
                res.push_back(curr->data);
            }

            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addrightboundary(node* root, vector<int>& res) {
        node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isleaf(curr)) {
                temp.push_back(curr->data);
            }

            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    void addleaves(node* root, vector<int>& res) {
        if (isleaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left) addleaves(root->left, res);
        if (root->right) addleaves(root->right, res);
    }

    vector<int> printboundary(node* root) {
        vector<int> res;
        if (!root) return res;

        if (!isleaf(root)) {
            res.push_back(root->data);
        }

        addleftboundary(root, res);
        addleaves(root, res);
        addrightboundary(root, res);

        return res;
    }
};

void printresult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    solution sol;
    vector<int> result = sol.printboundary(root);

    cout << "boundary traversal: ";
    printresult(result);

    return 0;
}