#include <bits/stdc++.h>
using namespace std;

vector<int> findnse(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findnge(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findpsee(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findpgee(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

long long sumsubarraymins(vector<int> &arr) {
    vector<int> nse = findnse(arr);
    vector<int> psee = findpsee(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        sum += left * right * arr[i];
    }
    return sum;
}

long long sumsubarraymaxs(vector<int> &arr) {
    vector<int> nge = findnge(arr);
    vector<int> pgee = findpgee(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - pgee[i];
        long long right =nge[i]-i;
        sum += left*right*arr[i];
    }
    return sum;
}

long long subarrayranges(vector<int> &arr) {
    return sumsubarraymaxs(arr) - sumsubarraymins(arr);
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << subarrayranges(arr);
    return 0;
}
