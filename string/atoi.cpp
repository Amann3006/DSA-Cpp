#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, sign = 1;
    long res = 0;

    // Skip leading whitespaces
    while (i < s.size() && s[i] == ' ') i++;

    if (i == s.size()) return 0;

    // Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Convert digits
    while (i < s.size() && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');

        // Overflow handling
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * res);
}

int main() {
    string input = "   -42";

    int result = myAtoi(input);
    cout << "Converted integer: " << result << endl;

    return 0;
}
