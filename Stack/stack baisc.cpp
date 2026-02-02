#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element = " << s.top() << endl;

    s.pop();
    cout << "After pop, Top = " << s.top() << endl;

    if(s.empty())
        cout << "Stack is Empty";
    else
        cout << "Stack size = " << s.size();
}
