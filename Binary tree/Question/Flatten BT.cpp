#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:

    //==========================
    // Approach 1 : Recursive (Reverse Preorder)
    // Time : O(N)
    // Space : O(H)
    //==========================

    TreeNode* prev = NULL;

    void flattenRecursive(TreeNode* root) {
        if (!root) return;

        flattenRecursive(root->right);
        flattenRecursive(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    //==========================
    // Approach 2 : Stack
    // Time : O(N)
    // Space : O(N)
    //==========================

    void flattenStack(TreeNode* root) {

        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);

            if (!st.empty())
                curr->right = st.top();

            curr->left = NULL;
        }
    }

    //==========================
    // Approach 3 : Morris Traversal
    // Time : O(N)
    // Space : O(1)
    //==========================

    void flattenMorris(TreeNode* root) {

        TreeNode* curr = root;

        while (curr) {

            if (curr->left) {

                TreeNode* prev = curr->left;

                while (prev->right)
                    prev = prev->right;

                prev->right = curr->right;

                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }

    //==========================
    // Approach 4 : Recursive (Tail)
    // Time : O(N)
    // Space : O(H)
    //==========================

    TreeNode* helper(TreeNode* root) {

        if (!root)
            return NULL;

        TreeNode* leftTail = helper(root->left);
        TreeNode* rightTail = helper(root->right);

        if (leftTail) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        if (rightTail)
            return rightTail;

        if (leftTail)
            return leftTail;

        return root;
    }

    void flattenTail(TreeNode* root) {
        helper(root);
    }
};

// Print Flattened Tree
void print(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}

// Build Sample Tree
TreeNode* buildTree() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    return root;
}

int main() {

    TreeNode* root = buildTree();

    Solution obj;

    // Uncomment ONE approach at a time

    obj.flattenRecursive(root);

    // obj.flattenStack(root);

    // obj.flattenMorris(root);

    // obj.flattenTail(root);

    print(root);

    return 0;
}