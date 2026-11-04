#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the cheapest price using at most k stops.
    long long findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Use a wide sentinel outside valid accumulated prices.
        const long long INF = numeric_limits<long long>::max() / 4;

        // Store prices using a wide integer type.
        vector<long long> distance(n, INF);

        // Set the zero-flight price for the source city.
        distance[src] = 0;

        // Build prices using at most k + 1 flights.
        for (int used = 0; used <= k; used++) {
            vector<long long> nextDistance = distance;

            // Relax every directed flight from the previous layer.
            for (const vector<int>& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                long long price = flight[2];

                // Skip unreachable departure cities.
                if (distance[from] == INF) {
                    continue;
                }

                // Update only the next flight-count layer.
                nextDistance[to] = min(
                    nextDistance[to],
                    distance[from] + price
                );
            }

            // Move to the next layer after all flights are relaxed.
            distance = nextDistance;
        }

        // Convert an unreachable destination into -1.
        return distance[dst] == INF ? -1 : distance[dst];
    }
};

// Driver code.
int main() {
    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100},
        {1, 3, 600}, {2, 3, 200}
    };

    Solution solution;

    cout << solution.findCheapestPrice(n, flights, 0, 3, 1);

    return 0;
}