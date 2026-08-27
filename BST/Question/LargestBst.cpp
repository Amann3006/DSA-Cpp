#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Node {
public:
    int sum, minVal, maxVal;

    Node(int s, int mn, int mx) {
        sum = s;
        minVal = mn;
        maxVal = mx;
    }
};

class Solution {
public:
    int ans = 0;

    Node helper(TreeNode* root) {

        if (root == nullptr) {
            return Node(0, INT_MAX, INT_MIN);
        }

        Node left = helper(root->left);
        Node right = helper(root->right);

        if (root->val > left.maxVal &&
            root->val < right.minVal) {

            int total = left.sum + right.sum + root->val;

            ans = max(ans, total);

            return Node(
                total,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            );
        }

        return Node(0, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};

int main() {

    /*
             5
            / \
           4   8
              / \
             6   9
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;

    cout << "Maximum Sum BST = "
         << obj.maxSumBST(root) << endl;

    return 0;
}