#include <iostream>
#include<string>
#include<algorithm>
using namespace std;



int maxdiff(int arr[],int n){
    int res=arr[1]-arr[0];
    for(int i=0; i<n-1; i++){
        for(int j=i+1;  j<n; j++){
            res=max(res,arr[j]-arr[i]);
        }
    }
    return res;
}

//better

int maxdiff2(int arr[],int n){
    int res=arr[1]-arr[0];
    int minval=arr[0];

    for(int i=1; i<n; i++){
         res = max(res, arr[i] - minval);
        minval = min(minval, arr[i]);
    }

    return res;
    
}

int main(){

     int arr[]={7,10,4,10,6,5,2};
     int n=7;

    cout<<maxdiff(arr,n);
     
}