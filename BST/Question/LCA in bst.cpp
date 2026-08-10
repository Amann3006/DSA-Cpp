#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while (root != nullptr) {

            // Both p and q are greater than root
            if (root->val < q->val && root->val < p->val) {
                root = root->right;
            }

            // Both p and q are smaller than root
            else if (root->val > q->val && root->val > p->val) {
                root = root->left;
            }

            // One is on each side OR root is p/q
            else {
                return root;
            }
        }

        return nullptr;
    }
};

int main() {

    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
             / \
            3   5
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Find LCA of 2 and 8
    TreeNode* p = root->left;          // 2
    TreeNode* q = root->right;         // 8

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    if (ans != nullptr)
        cout << "Lowest Common Ancestor = " << ans->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}