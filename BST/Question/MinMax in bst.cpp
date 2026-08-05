#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int minValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    Node* curr = root;

    // leftmost node is minimum so we move in BST till
    // left node is not nullptr
    while (curr->left != nullptr) {
        curr = curr->left;
    }

    // returning the data at the leftmost node
    return curr->data;
}

int maxValue(Node* root) {
    // Base case
    if (root == NULL) {
        return -1;
    }

    Node* curr = root;

    // Rightmost node is maximum, so move 
    // till right is not NULL
    while (curr->right != NULL) {
        curr = curr->right;
    }

    // Returning the data at the rightmost node
    return curr->data;
}


int main() {

    // Representation of input binary search tree
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   / 
    //  1
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << minValue(root) <<" "<<endl;
    cout << maxValue(root) <<" ";

    return 0;
}
