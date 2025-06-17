#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void freq(int arr[],int n ){
    int freq=1,i=1;

    while(i<n){
        while(i<n&&arr[i]==arr[i-1]){
            freq++;
            i++;
        }
        cout<<arr[i-1]<<" --"<<freq<<endl;
        freq=1;
        i++;
    }

    if(n==1 || arr[n-1]!=arr[n-2]){
        cout<<arr[n-1]<<" "<<i;
    }
}



int main(){

     int arr[]={10,10,10,25,30,30};
     int n=sizeof(arr)/sizeof(arr[0]);

     freq(arr,n);

     
}