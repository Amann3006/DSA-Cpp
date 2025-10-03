#include<bits/stdc++.h>
using namespace std;
//optimal 0(nlogn)
int solve(int arr[],int n){
    unordered_map<int,int>mpp;
    int sum=0;
    int maxi=0;
    for(int i=0; i<n; i++){
      sum+=arr[i];

      if(sum==0){
        maxi=i+1;
      }
      else{
        if(mpp.find(sum)!=mpp.end()){
            maxi=max(maxi,i-mpp[sum]);
        }
        else{
            mpp[sum]=i;
        }
      }
    }
    return maxi;
}

int main(){
    int arr[]={1,-1,3,2,-2,-8,1,7,10,2,3};
      int n = sizeof(arr) / sizeof(arr[0]);     

      cout<<solve(arr,n);
}