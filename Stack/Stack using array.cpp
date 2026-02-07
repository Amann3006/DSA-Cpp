#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Top = " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.peek();
    s.pop();
    s.peek();
}
