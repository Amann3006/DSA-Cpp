#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int>& arr){
    int m = INT_MIN;
    for(int x : arr){
        m = max(m, x);
    }
    return m;
}

long long func(vector<int>& arr, int mid){
    long long totalh = 0;
    for(int x : arr){
        totalh += (x + mid - 1) / mid; 
    }
    return totalh;
}

int main() {
    int n, h;
    cin >> n >> h; 
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int low = 1, high = maxi(arr);
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high - low) / 2;
        long long totalh = func(arr, mid);

        if(totalh <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
  