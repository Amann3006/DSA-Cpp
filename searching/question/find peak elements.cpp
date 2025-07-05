#include<iostream>
using namespace std;


int getpeak(int arr[],int n){
    if(n==1){
        return arr[0];
    }

    if(arr[0]>=arr[1]){
        return arr[0];
    }

    if(arr[n-1]>=arr[n-2]){
        return arr[n-1];
    }

    for(int i=1; i<n; i++){
         if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
            return arr[i];
         }
    }
    return -1;
}
//using binary search 

int getpeak1(int arr[],int n){
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;
      if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        return mid;
      }

      if(mid>0 && arr[mid-1]>=arr[mid]){
        e=mid-1;
      }
      else{
        s=mid+1;
      }
      
    }
    return -1;
}



int main(){
    int arr[]={5,20,40,30,20,50,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout<<getpeak(arr,n)<<endl;
    cout<<getpeak1(arr,n);
}