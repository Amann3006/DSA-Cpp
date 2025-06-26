#include <iostream>
using namespace std;


bool issubsum(int arr[],int n,int sum){
    for(int i=0; i<n; i++){
        int curr=0; 
        for(int j=i; j<n; j++){
            curr=curr+arr[j];
           if(curr==sum){
            return true;
           }
        }
    }
    return false;
   
}
//using window sliding algo
bool issubsum2(int arr[],int n,int sum){
    int s=0;
    int curr=0;
    for(int e=0; e<n; e++){
        curr+=arr[e];
        while(sum<curr){
            curr-=arr[s];
            s++;
        }
        if(sum==curr){
            return true;
        }
    }
    return false;
}


int main(){
    int arr[]={3,2,0,4,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cin>>sum;
    
   cout <<issubsum(arr,n,sum)<<endl;
   cout<<issubsum2(arr,n,sum);
}