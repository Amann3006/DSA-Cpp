#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = rearNode = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(rearNode == NULL) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if(frontNode == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if(frontNode == NULL)
            rearNode = NULL;

        delete temp;
    }

    // Front operation
    int front() {
        if(frontNode == NULL) return -1;
        return frontNode->data;
    }

    // Check empty
    bool empty() {
        return frontNode == NULL;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    cout << q.front() << endl; // 5
    q.dequeue();
    cout << q.front() << endl; // 15

    return 0;
}
