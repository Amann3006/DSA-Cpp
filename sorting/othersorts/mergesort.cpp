#include<iostream>
#include <limits>
#include<algorithm>
using namespace std;
   
//normal solution
void mergesort(int arr[],int arr1[],int n,int n1){
     int c[n+n1];

    for(int i=0; i<n; i++){
        c[i]=arr[i];
    }
    for(int i=0; i<n1; i++){
        c[n+i]=arr1[i];
    }

    sort(c,c+n1+n);
     

   for(int i=0; i<n+n1; i++){
    cout<<c[i]<<" ";
   }
}

//T.C 0(n+n1) S.C 0(1)
void mergesort2(int arr[],int arr1[],int n,int n1){
    int i=0,j=0;
    while(i<n &&j<n1){
        if(arr[i]<=arr1[j]){
            cout<<arr[i]<<" ";
            i++;
        }
        else{
            cout<<arr1[j]<<" ";
            j++;
        }
    }
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
    while(j<n1){
        cout<<arr[j]<<" ";
        j++;
    }
}

int main(){
    int arr[]={10,15,20,20};
    int arr1[]={1,12};
    int n=sizeof(arr) / sizeof(arr[0]);
    int n1=sizeof(arr1) / sizeof(arr1[0]);

    mergesort(arr,arr1,n,n1);
    cout<<endl;
    mergesort2(arr,arr1,n,n1);

}