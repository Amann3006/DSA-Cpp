#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
       
     int arr[]={1,-1,-1,1,1,-1};
     int n=6;
     int newarr[n]={};
     

     for(int i=0; i<n; i++){
        if(arr[i]>=0){
            arr[i]=-1;

        }
        else {
              arr[i]=arr[i];
        }

     }

     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
     }
       
} 