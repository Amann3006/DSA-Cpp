#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


bool epoint(int arr[],int n){
    for(int i=0; i<n; i++){
        int ls=0; 
        int rs=0;
        for(int j=0; j<i; j++){
            ls+=arr[j];
        }
        for(int k=i+1; k<n; k++){
            rs+=arr[k];
        }

        if(ls==rs){
            return true;
        }
    }
    return false;
}

//o(n);
bool epoint1(int arr[],int n){
   int res=0;
    for(int i=0; i<n; i++){
    res+=arr[i];
    }

    int ls=0;
    for(int i=0; i<n; i++){
        res-=arr[i];

        if(res==ls){
            return true;
        }
        ls+=arr[i];

    }

    return false;
}


int main(){
    int arr[]={3,4,8,-9,9,7};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<epoint(arr,n)<<endl;
    cout<<epoint1(arr,n);
   
} 