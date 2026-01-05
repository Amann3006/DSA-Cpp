#include <bits/stdc++.h>
using namespace std;

// Function to check if substring s[start...end] is a palindrome
bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

// Backtracking function to build partitions
void backtrack(int index, string &s, vector<string> &path, 
               vector<vector<string>> &res) {
    
    if (index == s.length()) {
        res.push_back(path);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            backtrack(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

// Main function to return all palindrome partitions
vector<vector<string>> partitionString(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtrack(0, s, path, res);
    return res;
}

// Driver code
int main() {
    string s = "aab";
    vector<vector<string>> ans = partitionString(s);

    for (auto &vec : ans) {
        for (auto &str : vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
