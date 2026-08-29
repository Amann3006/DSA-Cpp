#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    // ==============================
    // 1. Adjacency Matrix
    // ==============================

    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        // Undirected graph
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "\nAdjacency Matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }


    // ==============================
    // 2. Adjacency List
    // ==============================

    vector<vector<int>> adjList(n + 1);

    // We need to take the edges again
    cout << "\nEnter edges again for adjacency list:\n";

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        // Undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "\nAdjacency List:\n";

    for (int i = 1; i <= n; i++) {

        cout << i << " -> ";

        for (int node : adjList[i]) {
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}