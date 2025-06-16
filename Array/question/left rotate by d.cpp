#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


void leftrotate(int arr[],int n){

     int temp=arr[0];
     for(int i=1; i<n; i++){
        arr[i-1]=arr[i];
     }
     arr[n-1]=temp;
}

void leftrotate1(int arr[],int n,int d){
    for(int i=0; i<d; i++){
        leftrotate(arr,n);
    }
}
//better 
void leftrotate2(int arr[],int n,int d){

    int temp[d];

    for(int i=0; i<d; i++){
        temp[i]=arr[i];
    }

    for(int i=d; i<n; i++){
        arr[i-d]=arr[i];
    }
    for(int i=0; i<d; i++){
        arr[n-d+i]=temp[i];
    }
}



void reversearray(int arr[], int low, int high) {
    while (low < high) {
        swap(arr[low], arr[high]);
        low++;
        high--;  
    }
}

void leftrota(int arr[], int n, int d) {
    reversearray(arr, 0, d - 1);     // Reverse the first d elements
    reversearray(arr, d, n - 1);     // Reverse the remaining n - d elements
    reversearray(arr, 0, n - 1);     // Reverse the entire array
}





int main(){
    int arr[]={1,3,0,20};
    int n=4;
    int d;
    cin>>d;
    leftrota(arr,n,d);

    for(int i=0; i<n; i++ ){
        cout<<arr[i]<<" ";
    }
}