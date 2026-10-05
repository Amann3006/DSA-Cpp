#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    // Undirected graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin >> src;

    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node]) {

            // Not visited
            if (dist[neighbour] == -1) {
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }

    // Shortest distance from source to every node
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}