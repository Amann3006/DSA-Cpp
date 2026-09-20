#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col,
         vector<vector<int>>& vis,
         vector<vector<int>>& mat,
         vector<int>& delrow,
         vector<int>& delcol) {

    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();

    for (int k = 0; k < 4; k++) {

        int nrow = row + delrow[k];
        int ncol = col + delcol[k];

        if (nrow >= 0 && nrow < n &&
            ncol >= 0 && ncol < m &&
            mat[nrow][ncol] == 1 &&
            !vis[nrow][ncol]) {

            dfs(nrow, ncol, vis, mat, delrow, delcol);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    int cnt = 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    // First row and last row
    for (int j = 0; j < m; j++) {

        if (!vis[0][j] && grid[0][j] == 1) {
            dfs(0, j, vis, grid, delrow, delcol);
        }

        if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
            dfs(n - 1, j, vis, grid, delrow, delcol);
        }
    }

    // First column and last column
    for (int i = 0; i < n; i++) {

        if (!vis[i][0] && grid[i][0] == 1) {
            dfs(i, 0, vis, grid, delrow, delcol);
        }

        if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
            dfs(i, m - 1, vis, grid, delrow, delcol);
        }
    }

    // Count unvisited land cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1 && !vis[i][j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Number of Enclaves = " << numEnclaves(grid) << endl;

    return 0;
}