#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    Node* first;
    Node* middle;
    Node* prev;
    Node* last;

    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (prev != nullptr && root->data < prev->data) {

            if (first == nullptr) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(Node* root) {

        first = middle = last = nullptr;

        prev = new Node(INT_MIN);

        inorder(root);

        if (first && last) {
            swap(first->data, last->data);
        }
        else {
            swap(first->data, middle->data);
        }
    }
};

void printInorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {

    /*
            6
           / \
          7   8
         / \ / \
        1  4 3  9

        7 and 3 are swapped.

        Before:
        1 7 4 6 3 8 9

        After:
        1 3 4 6 7 8 9
    */

    Node* root = new Node(6);

    root->left = new Node(7);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout << "Before recovery: ";
    printInorder(root);

    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "After recovery:  ";
    printInorder(root);

    cout << endl;

    return 0;
}