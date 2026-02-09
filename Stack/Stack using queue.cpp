#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;

public:
    // Push operation
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // rotate previous elements
        for(int i = 1; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation
    void pop() {
        if(q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    // Top operation
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }

    // Check empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30
    st.pop();
    cout << st.top() << endl; // 20

    return 0;
}
