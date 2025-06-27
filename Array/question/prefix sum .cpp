#include <iostream>
#include<string>
#include<algorithm>
using namespace std;



int getsum(int arr[],int l,int e){
    int curr=0;
    for(int i=l; i<e; i++){
       curr+=arr[i];
    }
    return curr;
}


int main(){
    int arr[]={2,8,3,9,6,5,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<getsum(arr,0,3)<<endl;
    cout<<getsum(arr,1,4)<<endl;
    cout<<getsum(arr,2,5);
} 