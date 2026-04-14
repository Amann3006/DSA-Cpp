#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void allTraversal(Node* root) {
    vector<int> pre, in, post;

    if (root == NULL) return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        }

        // Inorder
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        }

        // Postorder
        else {
            post.push_back(it.first->data);
        }
    }

    // Print results
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    allTraversal(root);

    return 0;
}