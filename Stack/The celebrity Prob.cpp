#include <bits/stdc++.h>
using namespace std;

// function to find celebrity index
int celebrity(vector<vector<int>> &m) {
    int n = m.size();
    int top = 0, down = n - 1;

    // eliminate non-celebrities
    while (top < down) {
        if (m[top][down] == 1) {
            top++;          // top knows down → not celebrity
        } 
        else if (m[down][top] == 1) {
            down--;         // down knows top → not celebrity
        } 
        else {
            top++;
            down--;
        }
    }

    // possible celebrity = top
    for (int i = 0; i < n; i++) {
        if (i == top) continue;

        // celebrity knows no one and everyone knows celebrity
        if (m[top][i] == 1 || m[i][top] == 0)
            return -1;
    }

    return top;
}

int main() {
    vector<vector<int>> m = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}
    };

    int ans = celebrity(m);
    cout << "the index of celebrity is: " << ans;

    return 0;
}
