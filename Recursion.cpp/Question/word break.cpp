#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
    vector<bool> dp(n + 1, false);
    dp[0] = true;   // empty string is valid
    
    int maxLen = 0;
    for (auto &w : wordDict)
        maxLen = max(maxLen, (int)w.size());

    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - maxLen); j < i; j++) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (wordBreak(s, wordDict))
        cout << "True";
    else
        cout << "False";

    return 0;
}
