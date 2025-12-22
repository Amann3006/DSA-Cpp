#include <bits/stdc++.h>
using namespace std;

// Recursive function to count subsequences with sum = target
int countSubseq(int ind, int sum, vector<int> &nums) {

    // If sum becomes 0 → valid subsequence
    if (sum == 0) return 1;

    // If index exceeds array OR sum < 0 → not valid
    if (ind == nums.size() || sum < 0) return 0;

    // Include current element + Exclude current element
    int take = countSubseq(ind + 1, sum - nums[ind], nums);
    int notTake = countSubseq(ind + 1, sum, nums);

    return take + notTake;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;

    int ans = countSubseq(0, target, nums);

    cout << "Number of subsequences with target sum " 
         << target << ": " << ans << endl;

    return 0;
}
