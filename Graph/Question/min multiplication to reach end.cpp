#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int src, int end) {

        if (src == end) return 0;

        vector<int> dis(1000, 1e9);
        queue<pair<int, int>> q;

        q.push({src, 0});
        dis[src] = 0;

        while (!q.empty()) {

            int node = q.front().first;
            int steps = q.front().second;

            q.pop();

            for (int it : arr) {

                int num = (it * node) % 1000;

                if (steps + 1 < dis[num]) {

                    dis[num] = steps + 1;

                    if (num == end) {
                        return steps + 1;
                    }

                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 5, 7};
    int src = 3;
    int end = 30;

    cout << obj.minSteps(arr, src, end) << endl;

    return 0;
}