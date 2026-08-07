#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        // If root itself is the node to delete
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (root != NULL) {

            // Search in left subtree
            if (root->val > key) {

                if (root->left != NULL &&
                    root->left->val == key) {

                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }

            // Search in right subtree
            else {

                if (root->right != NULL &&
                    root->right->val == key) {

                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }


    TreeNode* helper(TreeNode* root) {

        // No left child
        if (root->left == NULL) {
            return root->right;
        }

        // No right child
        else if (root->right == NULL) {
            return root->left;
        }

        // Both children exist
        TreeNode* rightChild = root->right;

        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }


    TreeNode* findLastRight(TreeNode* root) {

        if (root->right == NULL) {
            return root;
        }

        return findLastRight(root->right);
    }
};


// Insert into BST
TreeNode* insert(TreeNode* root, int val) {

    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}


// Inorder traversal
void inorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}


int main() {

    TreeNode* root = NULL;

    // Create BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    cout << "Before deletion: ";
    inorder(root);

    // Delete node
    int key = 5;

    Solution obj;
    root = obj.deleteNode(root, key);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}