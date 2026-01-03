#include <bits/stdc++.h>
using namespace std;

// -------------------- INCLUDE-EXCLUDE RECURSIVE METHOD --------------------
void generateRec(int idx, string &s, string curr, vector<string> &res) {
    // Base case
    if (idx == s.size()) {
        res.push_back(curr);
        return;
    }

    // Include s[idx]
    generateRec(idx + 1, s, curr + s[idx], res);

    // Exclude s[idx]
    generateRec(idx + 1, s, curr, res);
}

// -------------------- BITMASK METHOD --------------------
vector<string> generateBitmask(string s) {
    int n = s.size();
    int total = 1 << n;
    vector<string> ans;

    for (int mask = 0; mask < total; mask++) {
        string subseq = "";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq += s[i];
            }
        }
        ans.push_back(subseq);
    }
    return ans;
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    string s = "abc";

    // Recursive include-exclude
    vector<string> recRes;
    generateRec(0, s, "", recRes);

    // Bitmask method
    vector<string> bitRes = generateBitmask(s);

    cout << "Recursive Include-Exclude:\n";
    for (auto &x : recRes) cout << x << " ";
    cout << "\n\nBitmask Method:\n";
    for (auto &x : bitRes) cout << x << " ";
}
