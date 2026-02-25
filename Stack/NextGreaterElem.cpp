#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    cout << "Brute Force NGE: ";
    for (int i = 0; i < n; i++) {
        int nge = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nge = arr[j];
                break;
            }
        }
        cout << nge << " ";
    }

    cout << endl;

    
    cout << "Optimized NGE:   ";
    vector<int> res(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
