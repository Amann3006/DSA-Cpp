#include <bits/stdc++.h>
using namespace std;

// ---------------- Recursive ----------------
int helper(string &s, int idx, int n) {
    if (idx == n) return 0;
    int digit = s[idx] - '0';
    int small = helper(s, idx + 1, n);
    int pow10 = pow(10, n - idx - 1);
    return digit * pow10 + small;
}

int atoiRecursive(string s) {
    int sign = 1, i = 0;
    if (s[0] == '-') sign = -1, i++;
    return sign * helper(s, i, s.size());
}

// ---------------- Iterative ----------------
int atoiIterative(string s) {
    int sign = 1, i = 0, ans = 0;
    if (s[0] == '-') sign = -1, i++;

    for (; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return sign * ans;
}

// ---------------- Main ----------------
int main() {
    string s1 = "-1234";
    cout << "Recursive: " << atoiRecursive(s1) << endl;

    string s2 = "5678";
    cout << "Iterative: " << atoiIterative(s2) << endl;

    return 0;
}
