#include <bits/stdc++.h>
using namespace std;

void func(int ind, string &digits, string s, vector<string> &ans, string combos[]) {
    // If full string built → store in ans
    if (ind == digits.size()) {
        if (!s.empty()) ans.push_back(s);
        return;
    }

    int digit = digits[ind] - '0';

    for (char c : combos[digit]) {
        func(ind + 1, digits, s + c, ans, combos);
    }
}

vector<string> letterCombinations(string digits) {
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    string s = "";

    if (digits.empty()) return ans;  // handle empty input

    func(0, digits, s, ans, combos);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    for (auto &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
