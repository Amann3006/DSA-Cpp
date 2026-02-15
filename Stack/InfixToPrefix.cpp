#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {
    // Step 1: Reverse string
    reverse(s.begin(), s.end());

    // Step 2: Swap brackets
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    // Step 3: Infix to Postfix
    stack<char> st;
    string postfix = "";

    for (char c : s) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) > precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << infixToPrefix(infix);
}
