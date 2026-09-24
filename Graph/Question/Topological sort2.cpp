#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Calculate indegree of every node
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    // Put all nodes with indegree 0 into queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        // Remove node's outgoing edges
        for (auto it : adj[node]) {
            indegree[it]--;

            // If indegree becomes 0
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If all vertices are processed, topological sort exists
    if (topo.size() != V) {
        return {};
    }

    return topo;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> ans = kahnTopoSort(V, adj);

    if (ans.empty()) {
        cout << "Cycle exists\n";
    } else {
        cout << "Topological Sort: ";

        for (auto x : ans) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}