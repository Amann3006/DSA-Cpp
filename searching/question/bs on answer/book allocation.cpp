#include <bits/stdc++.h>
using namespace std;

int countstudent(vector<int>& arr,int req) {
    int stucnt= 1;
    int pagest = 0;
    for(int i = 0; i < arr.size(); i++) {
         
        if(pagest+arr[i]<=req){
            pagest+=arr[i];
        }
        else{
            stucnt+=1;
            pagest=arr[i];
        }
         
    }
    return stucnt;
}
//binarys
int bookallocation(vector<int>& arr, int k){
    int low= *max_element(arr.begin(), arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int student=countstudent(arr,mid);
        if(student>k){
            low=mid+1;

        }
        else{
            high=mid-1;
        }

    }
    return low;
}

//brute force
int bookall(vector<int>& arr, int k) {
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    
    for(int i=maxi; i<=sum; i++){
        int cnts=countstudent(arr,i);
        if(cnts==k){
            return i;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n>> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << bookall(arr,k) << endl;
  cout << bookallocation(arr,k) << endl;
    return 0;
}
