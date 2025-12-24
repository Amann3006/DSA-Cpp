#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int>& candidates, int target,
           vector<vector<int>>& ans, vector<int>& temp) {

    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int ind = i; ind < candidates.size(); ind++) {

        // Skip duplicates
        if (ind > i && candidates[ind] == candidates[ind - 1])
            continue;

        // Stop if element is greater than remaining target
        if (candidates[ind] > target)
            break;

        temp.push_back(candidates[ind]);
        solve(ind + 1, candidates, target - candidates[ind], ans, temp);
        temp.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, candidates, target, ans, temp);

    return ans;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum2(candidates, target);

    for (auto& comb : result) {
        for (int x : comb) cout << x << " ";
        cout << endl;
    }
}
