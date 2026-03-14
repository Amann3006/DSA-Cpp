#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE (RECURSION) ===================== */
// Time: Exponential (TLE)
bool canJumpBrute(int idx, vector<int>& nums) {
    int n = nums.size();
    if (idx >= n - 1) return true;

    for (int jump = 1; jump <= nums[idx]; jump++) {
        if (canJumpBrute(idx + jump, nums)) return true;
    }
    return false;
}

//
// Time: O(N^2), Space: O(N)
bool canJumpMemoUtil(int idx, vector<int>& nums, vector<int>& dp) {
    int n = nums.size();
    if (idx >= n - 1) return true;
    if (dp[idx] != -1) return dp[idx];

    for (int jump = 1; jump <= nums[idx]; jump++) {
        if (canJumpMemoUtil(idx + jump, nums, dp))
            return dp[idx] = true;
    }
    return dp[idx] = false;
}

bool canJumpDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return canJumpMemoUtil(0, nums, dp);
}

// GREEDY(OPTIMAL)
// Time: O(N), Space: O(1)
bool canJumpGreedy(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << "Brute: " << canJumpBrute(0, nums) << endl;
    cout << "DP: " << canJumpDP(nums) << endl;
    cout << "Greedy: " << canJumpGreedy(nums) << endl;

    return 0;
}