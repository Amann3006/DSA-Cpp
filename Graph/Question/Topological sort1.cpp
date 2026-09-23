#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st,
             vector<int> adj[]) {

        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    Solution obj;

    vector<int> ans = obj.topoSort(V, adj);

    // Print topological order
    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}