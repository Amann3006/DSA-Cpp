#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& g) {
    int n = g.size();

    vector<int> indeg(n, 0);
    vector<vector<int>> adj(n);

    // Reverse the graph
    for (int i = 0; i < n; i++) {
        for (auto it : g[i]) {
            adj[it].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;

    // Terminal nodes
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safenode;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        safenode.push_back(node);

        for (auto i : adj[node]) {
            indeg[i]--;

            if (indeg[i] == 0) {
                q.push(i);
            }
        }
    }

    sort(safenode.begin(), safenode.end());

    return safenode;
}

int main() {

    vector<vector<int>> g = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = eventualSafeNodes(g);

    cout << "Safe nodes: ";

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}