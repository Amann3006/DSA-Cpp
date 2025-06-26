//find the max sumof k consecutive elements

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getmax(int arr[],int n,int k){
    int res=INT8_MIN;

    for(int i=0; i+k-1<n; i++){
        int curr=0;
      for(int j=0; j<k; j++){
        curr+=arr[i+j];
        res=max(res,curr);
      }
    }
return res;
}

//sliding window algo
int maxksum(int arr[],int n,int k){
  int curr=0;

  for(int i=0; i<k; i++){
    curr+=arr[i];
  }

  int res=curr;
  for(int i=k; i<n; i++){
  curr=curr+arr[i]-arr[i-k];
  res=max(curr,res);
   }
   return res;
  
  
}

int main(){
  int arr[]={1,8,30,-5,20,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin>>k;

    cout<<getmax(arr,n,k)<<endl;
    cout<<maxksum(arr,n,k);

}