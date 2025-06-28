#include<iostream>
using namespace std;

int binarysearch(int arr[],int s,int e,int x){
    
    if(s>e){
        return -1;
    }

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==x){
            return mid;
        }

         else if(arr[mid]>x){
           return binarysearch(arr,s,mid-1,x);
        }
        else{
           return binarysearch(arr,mid+1,e,x);
        }
    }
}

int main(){
    int arr[]={10,20,30,40,50,60};
    int x;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
   cout<< binarysearch(arr,0,n-1,x);
}
