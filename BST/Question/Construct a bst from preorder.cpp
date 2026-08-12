#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {

        if (i == A.size() || A[i] > bound)
            return NULL;

        TreeNode* root = new TreeNode(A[i++]);

        root->left = build(A, i, root->val);

        root->right = build(A, i, bound);

        return root;
    }
};

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> A = {8, 5, 1, 7, 10, 12};

    Solution obj;

    TreeNode* root = obj.bstFromPreorder(A);

    cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}