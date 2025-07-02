#include<iostream>
using namespace std;



int countone(int arr[],int n){
    int s=0,e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==0){
            s=mid+1;
        }

        else{
            //we are at first occ
            if(mid==0|| arr[mid-1]==0){
                return (n-mid);
            }

            else{
                e=mid-1;
            }

        }
    }
    return -1;
}


int main(){
    int arr[]={0,0,1,1,1,1};
    
    int n = sizeof(arr) / sizeof(arr[0]);
   cout<< countone(arr,n);
}
