#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;
}

string frequencySort(string s) {
    vector<pair<int, char>> freq(128);
    for (int i = 0; i < 128; i++) freq[i] = {0, (char)i};

    for (char ch : s) freq[ch].first++;

    sort(freq.begin(), freq.end(), comparator);

    string ans;
    for (auto &p : freq) ans.append(p.first, p.second);

    return ans;
}

int main() {
    string s = "2a554442f544asfasssffffasss";
    string result = frequencySort(s);
    cout << result;
    return 0;
}
