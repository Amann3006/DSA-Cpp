#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void leftrotate(int arr[],int n){
    int temp=arr[n-1]; //store 1 element
    for(int i=1; i<n; i++){
        arr[i+1]=arr[i];
        
    }
    //after loop {3,0,20,20}
    arr[0]=temp;
    //after this line
    //{3,0,20,1}
    
}


int main(){
    int arr[]={1,3,0,20};
    int n=4;

    leftrotate(arr,n);

    for(int i=0; i<n; i++ ){
        cout<<arr[i]<<" ";
    }
}