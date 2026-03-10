#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue operation
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue operation
    void dequeue() {
        if(s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Front operation
    int front() {
        if(s1.empty() && s2.empty()) return -1;

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Check empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl; // 10
    q.dequeue();
    cout << q.front() << endl; // 20

    return 0;
}
