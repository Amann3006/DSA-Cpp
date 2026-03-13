#include <bits/stdc++.h>
using namespace std;

int findcontentchildren(vector<int>& g, vector<int>& s) {
    int n = g.size(), m = s.size();

    int l = 0, r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (l < m && r < n) {
        if (g[r] <= s[l]) {
            r++;
        }
        l++;
    }
    return r;
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << findcontentchildren(g, s);
    return 0;
}