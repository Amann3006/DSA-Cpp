#include <bits/stdc++.h>
using namespace std;

int possible(vector<int>& arr,int cap){
    int load=0;
    int d=1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]+load>cap){
            d++;
            load=arr[i];
        }else{
            load+=arr[i];
        }
    }
    return d;
}

int shipWithinDays(vector<int>& arr,int days){
    int sum=accumulate(arr.begin(),arr.end(),0);
    int low=*max_element(arr.begin(),arr.end()),high=sum;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        int reqday=possible(arr,mid);
        if(reqday<=days){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int bruteForce(vector<int>& arr,int days){
    int sum=accumulate(arr.begin(),arr.end(),0);
    int low=*max_element(arr.begin(),arr.end()),high=sum;
    int ans=INT_MAX;
    for(int cap=low;cap<=high;cap++){
        int reqday=possible(arr,cap);
        if(reqday<=days){
            ans=min(ans,cap);
        }
    }
    return ans;
}

int main(){
    int n,days;
    cin>>n>>days;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<shipWithinDays(arr,days)<<endl;
    cout<<bruteForce(arr,days)<<endl;
}
