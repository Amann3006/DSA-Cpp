#include <iostream>
using namespace std;


void resv(int arr[],int n){
    int s=0;
    int e=n-1;

    while(s<e){
        int temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++;
        e--;
    }

}
   
int main(){
    int arr[]={20,3,20,20};
    int n=4;

    resv(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }

    
}