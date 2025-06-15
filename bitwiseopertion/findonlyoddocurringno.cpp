#include <iostream>
using namespace std;

//optimize solution

int findoddno1(int arr[],int n){
    int res=arr[0];
    for(int i=1; i<n; i++){
        res=res^arr[i];
    }
    return res;
}








int findoddno(int arr[],int n){

    
    for(int i=0; i<n; i++){
       int count=0;

       for(int j=0; j<n; j++){
        if(arr[i]==arr[j]){
            count++;
        }
        
       }
       if(count%2!=0){
            return arr[i];
        }
    }

}

int main(){

    int arr[]={4,4,7,4,8,7,7,7,8};
    int n=9;

    int ans=findoddno(arr,n);
    
    cout<<ans;
    cout<<findoddno1(arr,n);
}