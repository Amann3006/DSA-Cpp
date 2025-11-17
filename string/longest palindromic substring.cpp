#include <bits/stdc++.h>
using namespace std;

// Function to expand from center and return palindrome length
int expandFromCenter(const string &str, int left, int right) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

// Function to find longest palindromic substring
string longestPalindrome(const string &str) {
    int start = 0, end = 0;

    for (int center = 0; center < str.length(); center++) {
        int lenOdd = expandFromCenter(str, center, center);
        int lenEven = expandFromCenter(str, center, center + 1);

        int maxLen = max(lenOdd, lenEven);

        if (maxLen > end - start) {
            start = center - (maxLen - 1) / 2;
            end = center + maxLen / 2;
        }
    }

    return str.substr(start, end - start + 1);
}

int main() {
    string input = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(input) << endl;
    return 0;
}
