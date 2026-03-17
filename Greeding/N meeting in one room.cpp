#include <bits/stdc++.h>
using namespace std;

int maxMeetingsBrute(vector<int>& s, vector<int>& e) {
    int n = s.size();
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({s[i], e[i]});
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        int lastEnd = v[i].second;
        
        for(int j = 0; j < n; j++) {
            if(v[j].first >= lastEnd) {
                cnt++;
                lastEnd = v[j].second;
            }
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int maxMeetingsOptimal(vector<int>& s, vector<int>& e) {
    int n = s.size();
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({s[i], e[i]});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int cnt = 1;
    int lastEnd = v[0].second;
    
    for(int i = 1; i < n; i++) {
        if(v[i].first >= lastEnd) {
            cnt++;
            lastEnd = v[i].second;
        }
    }
    
    return cnt;
}

int main() {
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> e = {2, 4, 6, 7, 9, 9};

    cout << maxMeetingsBrute(s, e) << endl;
    cout << maxMeetingsOptimal(s, e) << endl;

    return 0;
}