#include <bits/stdc++.h>
using namespace std;

//
// OPTIMAL (Backtracking + skip dups)

void solve(int ind, vector<int>& nums,
           vector<vector<int>>& ans, vector<int>& temp) {

    ans.push_back(temp);

    for (int i = ind; i < nums.size(); i++) {

        // skip duplicates
        if (i > ind && nums[i] == nums[i - 1])
            continue;

        temp.push_back(nums[i]);
        solve(i + 1, nums, ans, temp);  // include
        temp.pop_back();                // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 2};

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, nums, ans, temp);

    // print result
    for (auto &v : ans) {
        cout << "{ ";
        for (int x : v) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
