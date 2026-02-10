#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if(topNode == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top operation
    int top() {
        if(topNode == NULL) return -1;
        return topNode->data;
    }

    // Check empty
    bool empty() {
        return topNode == NULL;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.push(25);

    cout << st.top() << endl; // 25
    st.pop();
    cout << st.top() << endl; // 15

    return 0;
}
