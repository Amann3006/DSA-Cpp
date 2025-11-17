#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(string s, int k) {
    int left = 0, res = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        res += (right - left + 1);
    }
    return res;
}


int countSubstrings(string s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;

    cout << "Count: " << countSubstrings(s, k) << endl; // Expected: 7
    return 0;
}
