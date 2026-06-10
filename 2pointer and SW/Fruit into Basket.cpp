#include <bits/stdc++.h>
using namespace std;

// brute force - o(n^2)
int totalfruit_bruteforce(vector<int>& fruits) {
    int n = fruits.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<int> st;
        for (int j = i; j < n; j++) {
            st.insert(fruits[j]);
            if (st.size() > 2) break;
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

// hashmap sliding window - o(n)
int totalfruit_hashmap(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int left = 0, ans = 0;

    for (int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;

        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}

// optimized two variable approach - o(n)
int totalfruit_optimized(vector<int>& fruits) {
    int lastfruit = -1, secondlastfruit = -1;
    int lastfruitstreak = 0, currcount = 0;
    int ans = 0;

    for (int fruit : fruits) {

        if (fruit == lastfruit || fruit == secondlastfruit) {
            currcount++;
        } else {
            currcount = lastfruitstreak + 1;
        }

        if (fruit == lastfruit) {
            lastfruitstreak++;
        } else {
            lastfruitstreak = 1;
            secondlastfruit = lastfruit;
            lastfruit = fruit;
        }

        ans = max(ans, currcount);
    }
    return ans;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};

    cout << "brute force: " << totalfruit_bruteforce(fruits) << endl;
    cout << "hashmap: " << totalfruit_hashmap(fruits) << endl;
    cout << "optimized: " << totalfruit_optimized(fruits) << endl;

    return 0;
}
