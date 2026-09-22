#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, int col, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = col;

        for (auto i : adj[node]) {

            if (vis[i] == -1) {
                if (dfs(i, !col, vis, adj) == false) {
                    return false;
                }
            }
            else if (vis[i] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {

        int n = g.size();

        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {

            if (vis[i] == -1) {

                if (dfs(i, 0, vis, g) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {

    vector<vector<int>> g = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    Solution obj;

    if (obj.isBipartite(g)) {
        cout << "Graph is Bipartite" << endl;
    }
    else {
        cout << "Graph is Not Bipartite" << endl;
    }

    return 0;
}