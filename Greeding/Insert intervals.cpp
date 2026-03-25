#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& arr, vector<int>& nt) {
    vector<vector<int>> ans;
    int i = 0;
    int n = arr.size();

    // Add all intervals that come before the new interval
    while (i < n && arr[i][1] < nt[0]) {
        ans.push_back(arr[i]);   // push complete interval
        i++;
    }

    // Merge overlapping intervals with new interval
    while (i < n && arr[i][0] <= nt[1]) {
        nt[0] = min(nt[0], arr[i][0]); // update start
        nt[1] = max(nt[1], arr[i][1]); // update end
        i++;
    }

    // Insert merged interval
    ans.push_back(nt);

    // Add remaining intervals
    while (i < n) {
        ans.push_back(arr[i]);
        i++;
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {{1,3},{6,9}};
    vector<int> nt = {2,5};

    vector<vector<int>> ans = insertInterval(arr, nt);

    for (auto &v : ans) {
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}