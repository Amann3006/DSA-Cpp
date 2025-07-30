#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
        // Step 2: Find the next larger element to swap with
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the suffix starting at i + 1
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
