#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE (Bitmask)

vector<int> subsetSumsBitmask(vector<int>& arr) {
    int n = arr.size();
    vector<int> sums;

    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += arr[i];  // include
        }
        sums.push_back(sum);
    }

    sort(sums.begin(), sums.end());
    return sums;
}


// OPTIMAL (Recursion)

void generateRec(int index, vector<int>& arr, int currentSum, vector<int>& result) {
    if (index == arr.size()) {
        result.push_back(currentSum);
        return;
    }

    generateRec(index + 1, arr, currentSum + arr[index], result); // include
    generateRec(index + 1, arr, currentSum, result);               // exclude
}

vector<int> subsetSumsRec(vector<int>& arr) {
    vector<int> result;
    generateRec(0, arr, 0, result);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {5, 2, 1};

    vector<int> bitmaskResult = subsetSumsBitmask(arr);
    vector<int> recursiveResult = subsetSumsRec(arr);

    cout << "Bitmask:\n";
    for (int sum : bitmaskResult) cout << sum << " ";
    cout << "\n\n";

    cout << "Recursion:\n";
    for (int sum : recursiveResult) cout << sum << " ";

    return 0;
}
