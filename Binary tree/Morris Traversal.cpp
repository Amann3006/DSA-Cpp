#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* curr = root;

        while (curr) {

            // No left child
            if (curr->left == NULL) {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else {
                // Find inorder predecessor
                Node* prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // Create thread
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                // Thread exists
                else {
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5

    Inorder: 4 2 5 1 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    vector<int> result = obj.inOrder(root);

    cout << "Inorder Traversal: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}