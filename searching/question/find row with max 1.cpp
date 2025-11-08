#include <bits/stdc++.h>
using namespace std;

int rowWithMax1sNaive(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int maxCount = 0;
    int rowIndex = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1)
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int firstOneIndex(vector<int>& row) {
    int low = 0, high = row.size() - 1;
    int ans = row.size();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] == 1) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1sBS(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int max1s = 0, rowIndex = -1;
    for (int i = 0; i < n; i++) {
        int idx = firstOneIndex(arr[i]);
        int count1s = m - idx;
        if (count1s > max1s) {
            max1s = count1s;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int rowWithMax1sOptimal(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int rowIndex = -1;
    int j = m - 1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int main() {
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    cout << "Row with max 1s (Naive): " << rowWithMax1sNaive(arr) << endl;
    cout << "Row with max 1s (Binary Search): " << rowWithMax1sBS(arr) << endl;
    cout << "Row with max 1s (Optimal O(n + m)): " << rowWithMax1sOptimal(arr) << endl;
    return 0;
}
