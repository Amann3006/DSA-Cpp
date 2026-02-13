#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (char c : s) {
        // Operand
        if (isalnum(c)) {
            ans += c;
        }
        // Left parenthesis
        else if (c == '(') {
            st.push(c);
        }
        // Right parenthesis
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix = "A+(B*C)";
    cout << infixToPostfix(infix);
}
