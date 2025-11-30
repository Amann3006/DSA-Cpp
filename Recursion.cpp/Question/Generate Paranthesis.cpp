#include <bits/stdc++.h>
using namespace std;

// ---------------- OPTIMAL BACKTRACKING ----------------
void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if ((int)curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) 
        backtrack(curr + '(', open + 1, close, n, res);

    if (close < open) 
        backtrack(curr + ')', open, close + 1, n, res);
}

vector<string> generateOptimal(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}


// ---------------- BRUTE FORCE METHOD ----------------
bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

void generateAll(string curr, int n, vector<string>& res) {
    if ((int)curr.length() == 2 * n) {
        if (isValid(curr)) res.push_back(curr);
        return;
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}

vector<string> generateBrute(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}


// ---------------- MAIN ----------------
int main() {
    int n = 3;

    cout << "Optimal Backtracking Output:\n";
    vector<string> opt = generateOptimal(n);
    for (string s : opt) cout << s << endl;

    cout << "\nBrute Force Output:\n";
    vector<string> brute = generateBrute(n);
    for (string s : brute) cout << s << endl;

    return 0;
}
