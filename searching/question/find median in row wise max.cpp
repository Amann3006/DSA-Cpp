#include <bits/stdc++.h>
using namespace std;

int medianNaive(vector<vector<int>>& mat) {
    vector<int> arr;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            arr.push_back(mat[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    return arr[arr.size()/2];
}

int countSmallerEqual(vector<int>& row, int x) {
    return upper_bound(row.begin(), row.end(), x) - row.begin();
}

int medianBS(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }
    int req = (n * m + 1) / 2;
    while(low < high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i=0;i<n;i++)
            cnt += countSmallerEqual(mat[i], mid);
        if(cnt < req) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Naive Median: " << medianNaive(mat) << endl;
    cout << "Binary Search Median: " << medianBS(mat) << endl;

    return 0;
}
