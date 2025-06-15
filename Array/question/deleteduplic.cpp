#include <iostream>
using namespace std;

int deledup(int arr[],int n){
    int temp[n];
    temp[0]=arr[0];
    int size=1;

    for(int i=1; i<n; i++){
        if(temp[size-1]!=arr[i]){
            temp[size]=arr[i];
            size++;
        }
    }
    for(int i=0; i<size; i++){
        arr[i]=temp[i];
    }
    return size;

}

//efficient apporoacg

int deledup2(int arr[],int n){
    int res=1;
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
   
int main(){
    int arr[]={20,3,3,20,20};
    int n=5;

   cout<< deledup(arr,n);
    cout<<deledup2(arr,n);
}