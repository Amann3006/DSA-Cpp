#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>>& edges, int src) {
    vector<vector<pair<int, int>>> adj(v);

    // Build adjacency list (undirected graph)
    for (auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated distances
        if (dis > dist[node]) {
            continue;
        }

        for (auto it : adj[node]) {
            int adjnode = it.first;
            int edgew = it.second;

            if (dis + edgew < dist[adjnode]) {
                dist[adjnode] = dis + edgew;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges(e);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }

    int src;
    cin >> src;

    vector<int> ans = dijkstra(v, edges, src);

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }

    cout << endl;

    return 0;
}