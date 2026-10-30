#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();

    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    queue<pair<int,int>> q;

    q.push({0, 0});
    grid[0][0] = 1;

    int dist = 1;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            pair<int,int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            if (r == n-1 && c == n-1)
                return dist;

            for (int i = 0; i < 8; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < n && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        dist++;
    }

    return -1;
}

int main() {

    vector<vector<int>> grid = {
        {0, 1, 1},
        {1, 0, 0},
        {0, 0, 0}
    };

    cout << shortestPathBinaryMatrix(grid) << endl;

    return 0;
}