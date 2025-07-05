#include<iostream>
using namespace std;


bool twopointer(int arr[],int n,int x){
int s=0; 
int e=n-1;

while(s<e){
    int sum=arr[s]+arr[e];
    if(sum==x){
        return true;
    }
    else if (sum>x){
        e--;
    }
    else{
        s++;
    }
 }
 return -1;
}

int main(){
    int arr[]={10,20,30,40,50,60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin>>x;
   
    cout<<twopointer(arr,n,x);
    

}