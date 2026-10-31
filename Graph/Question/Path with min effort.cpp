#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    dist[0][0] = 0;

    pq.push({0, {0, 0}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int effort = it.first;
        int x = it.second.first;
        int y = it.second.second;

        if (x == n - 1 && y == m - 1) {
            return effort;
        }

        if (effort > dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {

                int diff = abs(heights[x][y] - heights[nx][ny]);

                int newEffort = max(effort, diff);

                if (newEffort < dist[nx][ny]) {

                    dist[nx][ny] = newEffort;

                    pq.push({newEffort, {nx, ny}});
                }
            }
        }
    }

    return 0;
}

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << minimumEffortPath(heights);

    return 0;
}