#include <iostream>
using namespace std;


int sum(int arr[],int n){
    int res=arr[0];
    for(int i=0; i<n; i++){
        int curr=0; 
        for(int j=i; j<n; j++){
            curr=curr+arr[j];
            res=max(res,curr);
        }
    }
    return res;
}

int maxsum(int arr[],int n){
    int res=arr[0];
    int maxending=arr[0];

    for(int i=1; i<n; i++){
        maxending=max(maxending+arr[i],arr[i]);
        res=max(res,maxending);
    }
    return res;
}

int main(){
    int arr[]={-3,8,-2,4,-5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    
   cout <<sum(arr,n)<<endl;
   cout<<maxsum(arr,n);

}