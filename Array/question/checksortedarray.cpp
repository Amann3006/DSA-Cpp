#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


bool issorted(int arr[],int n){


    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}



int main(){
    int arr[]={10,20,30,40};
    int n=4;
    
    cout<<issorted(arr,n);
}