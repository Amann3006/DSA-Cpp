#include <bits/stdc++.h>
using namespace std;

// Brute force approach
string removeOuterParenthesesBrute(string s) {
    string result = "";
    stack<char> st;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        if (s[i] == '(') st.push('(');
        else st.pop();
        if (st.empty()) {
            result += temp.substr(1, temp.size() - 2);
            temp = "";
        }
    }
    return result;
}

// Optimal approach
string removeOuterParenthesesOptimal(string s) {
    string result = "";
    int level = 0;
    for (char ch : s) {
        if (ch == '(') {
            if (level > 0) result += ch;
            level++;
        } else {
            level--;
            if (level > 0) result += ch;
        }
    }
    return result;
}

int main() {
    string s = "(()())(())";
    cout << "Brute Force: " << removeOuterParenthesesBrute(s) << endl;
    cout << "Optimal: " << removeOuterParenthesesOptimal(s) << endl;
    return 0;
}
