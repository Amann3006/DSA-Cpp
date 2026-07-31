#include <bits/stdc++.h>
using namespace std;

int connectSticks(vector<int>& sticks) {

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Put all sticks into heap
    for (int i = 0; i < sticks.size(); i++) {
        pq.push(sticks[i]);
    }

    int total = 0;

    // Connect until only one stick remains
    while (pq.size() > 1) {

        int stick1 = pq.top();
        pq.pop();

        int stick2 = pq.top();
        pq.pop();

        int sum = stick1 + stick2;

        total += sum;

        // Put combined stick back
        pq.push(sum);
    }

    return total;
}

int main() {

    vector<int> sticks = {2, 4, 3, 6};

    cout << connectSticks(sticks) << endl;

    return 0;
}