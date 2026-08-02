#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        // Sort both arrays in descending order
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        // Max Heap -> {sum, i, j}
        priority_queue<tuple<int, int, int>> pq;

        // Visited set
        unordered_set<long long> visited;

        auto getKey = [&](int i, int j) {
            return 1LL * i * n + j;
        };

        // Push the largest sum
        pq.push({nums1[0] + nums2[0], 0, 0});
        visited.insert(getKey(0, 0));

        vector<int> ans;

        while (k-- && !pq.empty()) {

            tuple<int, int, int> temp = pq.top();
        pq.pop();

        int sum = get<0>(temp);
        int i   = get<1>(temp);
        int j   = get<2>(temp);

            ans.push_back(sum);

            // Down neighbour
            if (i + 1 < n && !visited.count(getKey(i + 1, j))) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert(getKey(i + 1, j));
            }

            // Right neighbour
            if (j + 1 < n && !visited.count(getKey(i, j + 1))) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert(getKey(i, j + 1));
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {6, 1};
    int k = 2;

    vector<int> ans = sol.maxCombinations(nums1, nums2, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}