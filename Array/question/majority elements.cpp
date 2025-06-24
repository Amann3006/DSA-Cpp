#include <iostream>
using namespace std;

int findmajority(int arr[],int n){
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
          if(arr[i]==arr[j]){
            count++;
          }
          if(count>n/2){
            return i;
          }
        }
    }
    return -1;
}

//better solution also know as moore algo
int majority(int arr[],int n){
     int res=0;
     int count=1;

     for(int i=1; i<n; i++){
        if(arr[res]==arr[i]){
            count++;
        }
        else{
            count--;
        }

        if(count==0){
            res=i;
            count=1;
        }
     }

     count=0;
     for(int i=0; i<n; i++){
        if(arr[res]==arr[i]){
            count++;
        }
     }
     if(count<=n/2){
        res=-1;
     }
     return res;
}


int main(){
      int arr[]={6,8,4,8,8};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout<<findmajority(arr,n)<<endl;
      cout<<majority(arr,n);

}