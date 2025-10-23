#include<iostream>
using namespace std;

int mini(int arr[],int n){
    int s=0;
    int e=n-1;
    int ans=INT8_MAX;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[s]<=arr[mid]){
            ans=min(ans,arr[s]);
            s=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            e=mid-1;
        }

     }
     return ans;
}

int main(){
    int arr[]={4,5,1,2,3};
   

    cout<<mini(arr,5);

}