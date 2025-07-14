#include<iostream>
#include <limits>
#include<algorithm>
using namespace std;
  

//in-place implementation

void selectsort1(int arr1[],int n){
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i+1; j<n; j++){
            if(arr1[j]<arr1[mini]){
            mini=j;
            }
        }
        swap(arr1[mini],arr1[i]);
    }
}
  
int main(){
    int arr[]={10,2,5,8,10,18,20};
    int n=sizeof(arr) / sizeof(arr[0]);

   selectsort1(arr,n);

   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
   }

}