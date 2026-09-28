#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses,
                      vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // [a,b] => b -> a
    for (auto it : prerequisites) {

        int a = it[0];
        int b = it[1];

        adj[b].push_back(a);
        indegree[a]++;
    }

    queue<int> q;

    // Courses having no prerequisite
    for (int i = 0; i < numCourses; i++) {

        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        // Remove this node
        for (auto it : adj[node]) {

            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Cycle exists
    if (ans.size() != numCourses) {
        return {};
    }

    return ans;
}

int main() {

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans = findOrder(numCourses, prerequisites);

    if (ans.empty()) {
        cout << "No valid order\n";
    }
    else {
        for (auto x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}