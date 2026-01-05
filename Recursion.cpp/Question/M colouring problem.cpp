#include <bits/stdc++.h>
using namespace std;

// Check if it's safe to color this node with given color
bool isSafe(int node, vector<int> &color,
            vector<vector<int>> &graph, int n, int col) {

    for (int k = 0; k < n; k++) {
        // if node k is adjacent and already has same color
        if (graph[node][k] == 1 && color[k] == col)
            return false;
    }
    return true;
}

// Backtracking function
bool solve(int node, vector<int> &color,
           int m, int n, vector<vector<int>> &graph) {

    if (node == n)   // all nodes colored
        return true;

    for (int col = 1; col <= m; col++) {

        if (isSafe(node, color, graph, n, col)) {
            color[node] = col;

            if (solve(node + 1, color, m, n, graph))
                return true;

            color[node] = 0;   // backtrack
        }
    }
    return false;
}

// Main coloring function
bool graphColoring(vector<vector<int>> &graph, int m, int n) {
    vector<int> color(n, 0);

    return solve(0, color, m, n, graph);
}

int main() {

    int N = 4;     // number of nodes
    int m = 3;     // max colors

    // adjacency matrix using vector
    vector<vector<int>> graph(N, vector<int>(N, 0));

    // sample graph
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    cout << graphColoring(graph, m, N);

    return 0;
}
