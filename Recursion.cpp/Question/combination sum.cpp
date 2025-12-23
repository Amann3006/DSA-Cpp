#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int>& candidates, int target,
           vector<vector<int>>& ans, vector<int>& temp) {

    if (i == candidates.size()) {
        if (target == 0) {
            ans.push_back(temp);
        }
        return;
    }

    // PICK (allowed only if candidates[i] <= target)
    if (candidates[i] <= target) {
        temp.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], ans, temp);
        temp.pop_back();  // backtrack
    }

    // NOT PICK
    solve(i + 1, candidates, target, ans, temp);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, candidates, target, ans, temp);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    for (auto& vec : result) {
        for (auto& x : vec) cout << x << " ";
        cout << endl;
    }

    return 0;
}
