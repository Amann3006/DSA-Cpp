#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    string prefix;
    cin >> prefix;

    stack<string> st;

    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // Operand
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // Operator
        else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expr = op1 + op2 + c;
            st.push(expr);
        }
    }

    cout << "Postfix Expression: " << st.top();
    return 0;
}
