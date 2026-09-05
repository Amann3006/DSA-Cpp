#include <bits/stdc++.h>
using namespace std;

// Solution class to hold the main logic
class Solution {
private:
    // Function to perform DFS traversal
    void dfs(int node, vector<int> adjList[], int visited[]) {
        // Mark current node as visited
        visited[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    // Function to count number of connected components
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create adjacency list from adjacency matrix
        vector<int> adjList[V];

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Array to keep track of visited nodes
        int visited[V] = {0};

        // Count of connected components
        int count = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If node is not visited
            if (!visited[i]) {
                // Perform DFS and increment count
                count++;
                dfs(i, adjList, visited);
            }
        }

        // Return final count
        return count;
    }
};

// Main function to drive the program
int main() {
    // Adjacency matrix input
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Number of vertices
    int V = 3;

    // Create object of Solution
    Solution obj;

    // Call the function and print result
    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}