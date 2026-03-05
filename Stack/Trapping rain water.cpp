#include <bits/stdc++.h>
using namespace std;

int trapBrute(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        int maxLeft = 0, maxRight = 0;

        for (int j = 0; j <= i; j++)
            maxLeft = max(maxLeft, height[j]);

        for (int j = i; j < n; j++)
            maxRight = max(maxRight, height[j]);

        totalWater += min(maxLeft, maxRight) - height[i];
    }

    return totalWater;
}

int trapOptimal(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int totalWater = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft)
                maxLeft = height[left];
            else
                totalWater += maxLeft - height[left];
            left++;
        } else {
            if (height[right] >= maxRight)
                maxRight = height[right];
            else
                totalWater += maxRight - height[right];
            right--;
        }
    }

    return totalWater;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trapBrute(height) << endl;
    cout << trapOptimal(height) << endl;

    return 0;
}
