#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Store nodes after exploring outgoing edges.
    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<int>& visited, stack<int>& topo) {
        // Mark current node visited.
        visited[node] = 1;

        // Visit every outgoing neighbor.
        for (auto& edge : adj[node]) {
            int nextNode = edge.first;
            if (!visited[nextNode]) {
                dfs(nextNode, adj, visited, topo);
            }
        }

        // Push after descendants to create topological order.
        topo.push(node);
    }

public:
    // Return shortest distances from source 0 in a weighted DAG.
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);

        // Build directed weighted adjacency list.
        for (vector<int>& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adj[from].push_back({to, weight});
        }

        vector<int> visited(V, 0);
        stack<int> topo;

        // Run DFS from every component to cover all vertices.
        for (int node = 0; node < V; node++) {
            if (!visited[node]) {
                dfs(node, adj, visited, topo);
            }
        }

        const int INF = 1e9;
        vector<int> dist(V, INF);

        // Source vertex is fixed as 0.
        dist[0] = 0;

        // Relax edges following topological order.
        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();

            // Skip vertices unreachable from source.
            if (dist[node] == INF) {
                continue;
            }

            // Improve distances of outgoing neighbors.
            for (auto& edge : adj[node]) {
                int nextNode = edge.first;
                int weight = edge.second;
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                }
            }
        }

        // Convert unreachable vertices from INF to -1.
        for (int node = 0; node < V; node++) {
            if (dist[node] == INF) {
                dist[node] = -1;
            }
        }

        return dist;
    }
};

// Driver code.
int main() {
    int V = 6;
    int E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2},
        {1, 2, 3}, {2, 3, 6}, {5, 3, 1}
    };
    Solution sol;
    vector<int> ans = sol.shortestPath(V, E, edges);

    // Print shortest distances.
    for (int value : ans) {
        cout << value << " ";
    }
    return 0;
}