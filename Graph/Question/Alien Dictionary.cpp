
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<int> adj[], int V, vector<int>& present) {
    queue<int> q;
    vector<int> indegree(V, 0);

    // Calculate indegree
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (present[node]) {
            topo.push_back(node);
        }

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;
}

string findOrder(vector<string>& words) {
    vector<int> present(26, 0);

    // Mark present characters
    for (auto it : words) {
        for (char ch : it) {
            present[ch - 'a'] = 1;
        }
    }

    int uniquechar = 0;
    for (int i = 0; i < 26; i++) {
        if (present[i]) uniquechar++;
    }

    int N = words.size();
    vector<int> adj[26];

    // Build graph
    for (int i = 0; i < N - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];

        int mini = min(s1.size(), s2.size());
        bool check = true;

        for (int k = 0; k < mini; k++) {
            if (s1[k] != s2[k]) {
                check = false;
                adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                break;
            }
        }

        // Invalid prefix
        if (check && s1.size() > s2.size()) return "";
    }

    vector<int> topo = topoSort(adj, 26, present);

    string ans = "";
    for (auto it : topo) {
        ans += char(it + 'a');
    }

    // Cycle detection
    if (uniquechar != ans.size()) return "";

    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    cout << findOrder(words) << '\n';

    return 0;
}