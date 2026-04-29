#include <bits/stdc++.h>
using namespace std;

// Tree Node Definition
struct treenode {
    int val;
    treenode* left;
    treenode* right;

    treenode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int maxPathSum(treenode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(treenode* node, int &maxSum) {
        if (!node) return 0;

        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));

        maxSum = max(maxSum, left + right + node->val);

        return max(left, right) + node->val;
    }
};

int main() {
    treenode* root = new treenode(-10);
    root->left = new treenode(9);
    root->right = new treenode(20);
    root->right->left = new treenode(15);
    root->right->right = new treenode(7);

    Solution obj;
    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << endl;

    return 0;
}      