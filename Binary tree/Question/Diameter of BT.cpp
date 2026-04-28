#include <iostream>
#include <algorithm>

using namespace std;

// node structure for the binary tree
struct node {
    int data;
    node* left;
    node* right;

    // Constructor
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(node* curr, int& diameter) {
        if (!curr) {
            return 0;
        }

        int lh = height(curr->left, diameter);
        int rh = height(curr->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);
    root->left->right->right->right = new node(7);

    Solution solution;

    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}