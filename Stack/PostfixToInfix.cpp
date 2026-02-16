#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    string postfix;
    cin >> postfix;

    stack<string> st;

    for (char c : postfix) {
        // If operand
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // If operator
        else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    cout << "Infix Expression: " << st.top();
    return 0;
}
