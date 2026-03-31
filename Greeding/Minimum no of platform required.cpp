#include <bits/stdc++.h>
using namespace std;

// ----------- BRUTE FORCE APPROACH (O(n^2)) -----------
int minPlatformsBrute(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    int maxPlat = 1;

    for (int i = 0; i < n; i++) {
        int platforms = 1; // current train needs 1 platform

        for (int j = 0; j < n; j++) {
            if (i != j) {
                // if trains overlap, increase platform count
                if (arr[i] <= dep[j] && arr[j] <= dep[i]) {
                    platforms++;
                }
            }
        }

        // store maximum platforms needed
        maxPlat = max(maxPlat, platforms);
    }

    return maxPlat;
}


// ----------- OPTIMAL APPROACH (SORT + TWO POINTER) -----------
int minPlatformsOptimal(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();

    // sort arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int platforms = 0, maxPlat = 0;

    // traverse both arrays
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;   // train arrives → need platform
            i++;
        } else {
            platforms--;   // train departs → free platform
            j++;
        }

        // track maximum platforms needed
        maxPlat = max(maxPlat, platforms);
    }

    return maxPlat;
}


// ----------- MAIN FUNCTION -----------
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Brute Force: " << minPlatformsBrute(arr, dep) << endl;
    cout << "Optimal: " << minPlatformsOptimal(arr, dep) << endl;

    return 0;
}