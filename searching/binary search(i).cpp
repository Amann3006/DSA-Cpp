#include<iostream>
using namespace std;

int binarysearch(int arr[],int x,int n){
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==x){
            return mid;
        }

         else if(arr[mid]>x){
           e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={10,20,30,40,50,60};
    int x;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
   cout<< binarysearch(arr,x,n);
}
