#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE (RECURSION)
// Time: Exponential (TLE)
int minJumpsBrute(int idx, vector<int>& nums) {
    int n = nums.size();
    if (idx >= n - 1) return 0;

    int ans = 1e9;
    for (int jump = 1; jump <= nums[idx]; jump++) {
        if (idx + jump < n) {
            ans = min(ans, 1 + minJumpsBrute(idx + jump, nums));
        }
    }
    return ans;
}

//DP (MEMOIZATION)
// Time: O(N^2), Space: O(N)
int minJumpsMemoUtil(int idx, vector<int>& nums, vector<int>& dp) {
    int n = nums.size();
    if (idx >= n - 1) return 0;
    if (dp[idx] != -1) return dp[idx];

    int ans = 1e9;
    for (int jump = 1; jump <= nums[idx]; jump++) {
        if (idx + jump < n) {
            ans = min(ans, 1 + minJumpsMemoUtil(idx + jump, nums, dp));
        }
    }
    return dp[idx] = ans;
}

int minJumpsDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return minJumpsMemoUtil(0, nums, dp);
}

//GREEDY (OPTIMAL)
// Time: O(N), Space: O(1)
int minJumpsGreedy(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);

        if (i == currEnd) {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}


int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << "Brute: " << minJumpsBrute(0, nums) << endl;
    cout << "DP: " << minJumpsDP(nums) << endl;
    cout << "Greedy: " << minJumpsGreedy(nums) << endl;

    return 0;
}