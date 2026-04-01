#include <bits/stdc++.h>
using namespace std;

int candySlope(vector<int>& arr) {
    int sum = 1;          // First child always gets 1 candy
    int i = 1;
    int n = arr.size();

    while (i < n) {

        // If ratings are equal, just give 1 candy
        if (arr[i] == arr[i - 1]) {
            sum = sum + 1;
            i++;
            continue;
        }

        // Handle increasing sequence (uphill)
        int peak = 1;     // Length of increasing slope
        while (i < n && arr[i] > arr[i - 1]) {
            peak = peak + 1;
            sum += peak;  // Give increasing candies
            i++;
        }

        // Handle decreasing sequence (downhill)
        int down = 1;     // Length of decreasing slope
        while (i < n && arr[i] < arr[i - 1]) {
            sum += down;  // Give decreasing candies
            i++;
            down++;
        }

        // If downhill is longer than uphill,
        // add extra candies to peak child
        if (down > peak) {
            sum = sum + (down - peak);
        }
    }

    return sum;
}



int candyTwoPass(vector<int>& ratings) {
    int n = ratings.size();

    // Step 1: Give each child 1 candy
    vector<int> candies(n, 1);

    // Step 2: Traverse Left → Right
    // If current rating > previous, increase candy count
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Traverse Right → Left
    // Ensure right neighbor condition is also satisfied
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Step 4: Sum all candies
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += candies[i];
    }

    return total;
}


int main() {
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    cout << "Slope Method: " << candySlope(ratings) << endl;
    cout << "Two Pass Method: " << candyTwoPass(ratings);

    return 0;
}