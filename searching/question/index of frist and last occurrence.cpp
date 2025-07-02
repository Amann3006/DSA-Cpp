#include<iostream>
using namespace std;

int binarysearch(int arr[],int s,int e,int x,int n){
    
    if(s>e){
        return -1;
    }
    
        int mid=s+(e-s)/2;

         if(arr[mid]>x){
           return binarysearch(arr,s,mid-1,x,n);  //for iterative just write e=mid-1;
        }
        else if(arr[mid]<x){
           return binarysearch(arr,mid+1,e,x,n); //for iterative just write s=mid+1;
        }

        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1]){
                return mid;
            }
            else{
                return binarysearch(arr,s,mid-1,x,n);  //for  first iterative just write e=mid-1 and for last s=mid+1;
            }
        }
    
}

int main(){
    int arr[]={10,20,30,30,50,50,60};
    int x;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
   cout<< binarysearch(arr,0,n-1,x,n);
}
