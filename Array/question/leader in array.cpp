#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void leader(int arr[],int n){
    for(int i=0; i<n; i++){
        bool isflag=false;
        for(int j=i+1; j<n; j++){
            if(arr[i]<=arr[j]){
                isflag=true;
                break;
            }
        }
        if(isflag==false){
            cout<<arr[i]<<" ";
        }

    }
}

//better solution 
void leader2(int arr[],int n){

    //going from last to first,last elements is always greater
    int currL=arr[n-1];
    cout<<currL<<" ";

    for(int i=n-1; i>=0; i--){
        if(currL<arr[i]){
            currL=arr[i];
            cout<<currL<<" ";
        }
    }
    
}


int main(){
    int arr[]={7,10,4,10,6,5,2};
    int n=7;
     
    leader(arr,n);
    cout<<endl;
    leader2(arr,n);
   
}