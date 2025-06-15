#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void movezero(int arr[],int n){
   
    
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            for(int j=i+1; j<n; j++){
                if(arr[i]!=0){
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
}

void movez(int arr[],int n){
    int count=0; 
    for(int i=0; i<n; i++){
        if(arr[i]!=arr[count]){
            swap(arr[i],arr[count]);
            count++;
        }
    }
}


int main(){
    int arr[]={0,3,0,20};
    int n=4;

    movezero(arr,n);
    movez(arr,n);
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }

}