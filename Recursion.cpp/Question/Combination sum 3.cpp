#include <bits/stdc++.h>
using namespace std;


void func(int sum, int last, vector<int> &curr, int k, vector<vector<int>> &ans) {
    // Valid combination found
    if (sum == 0 && curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    // Invalid cases
    if (sum <= 0 || curr.size() > k) return;

    for (int i = last; i <= 9; i++) {
        if (i > sum) break;

        curr.push_back(i);
        func(sum - i, i + 1, curr, k, ans);
        curr.pop_back();
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> curr;

    func(n, 1, curr, k, ans);

    return ans;
}

int main() {
    int k = 3;   // number of elements
    int n = 7;   // target sum

    vector<vector<int>> result = combinationSum3(k, n);

    for (auto &v : result) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
