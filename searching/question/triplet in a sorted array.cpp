#include<iostream>
using namespace std;


bool triplet(int arr[],int n,int x){

    for(int i=0; i<n-2; i++){
        
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                

                if(arr[i]+arr[j]+arr[k]==x){
                    return true;
                }
            }
        }
    }
    return false;
}

//0(n2)
bool ispair(int arr[],int n,int x,int si){
    int i=si;
    int j=n-1;

    while(i<j){
        if(arr[i]+arr[j]==x){
            return true;
        }
        else if(arr[i]+arr[j]<x){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

bool istriplet(int arr[],int n,int x){
    for(int i=0; i<n-2; i++){
        if(ispair(arr,n,x-arr[i],i+1)){
           return  true;
        }

    }
    return false;
}

int main(){
    int arr[]={2,5,10,15,18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin>>x;
     
    cout<<triplet(arr,n,x)<<endl;

    cout<<istriplet(arr,n,x);
}