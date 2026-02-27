#include <bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> maxslidingwindow_brute(vector<int>& nums, int k) {
    vector<int> ans;

    for (int i = 0; i <= nums.size() - k; i++) {
        int mx = nums[i];
        for (int j = i; j < i + k; j++) {
            mx = max(mx, nums[j]);
        }
        ans.push_back(mx);
    }

    return ans;
}

// optimal approach using deque
vector<int> maxslidingwindow_optimal(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {

        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> brute = maxslidingwindow_brute(arr, k);
    vector<int> optimal = maxslidingwindow_optimal(arr, k);

    cout << "brute: ";
    for (int x : brute) cout << x << " ";

    cout << "\noptimal: ";
    for (int x : optimal) cout << x << " ";

    return 0;
}
