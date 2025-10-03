#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t; // number of intervals
    vector<vector<int>> arr(t, vector<int>(2));

    for (int i = 0; i < t; i++) {
        cin >> arr[i][0] >> arr[i][1]; // input each interval [start, end]
    }

    vector<vector<int>> res = merge(arr);

    for (auto& interval : res) {
        cout << interval[0] << " " << interval[1] << endl;
    }
}
