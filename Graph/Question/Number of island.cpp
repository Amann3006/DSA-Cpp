#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            int delrow[4] = {-1, 1, 0, 0};
            int delcol[4] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {

                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {

                    cnt++;

                    bfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution obj;

    int ans = obj.numIslands(grid);

    cout << "Number of Islands = " << ans << endl;

    return 0;
}