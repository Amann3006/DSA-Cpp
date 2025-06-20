#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


int maxconsecutive(int arr[],int n){
    int res=0; 
    for(int i=0; i<n; i++){
        int count=0;
        for(int j=i; j<n; j++){
            if(arr[j]==1){
                count++;
            }
            else{
                break;
            }
        }
        res=max(res,count);
    }
    return res;
}

//better 0(N)
int maxcon1(int arr[],int n){
    int res=0;
    int count=0; 
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count=0;
        }
        else{
            count++;
            res=max(res,count);
        }
    }
    return res;
}


int main(){
    int arr[]={1,1,0,1,0,1,1,1,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<maxconsecutive(arr,n) <<endl;
    cout<<maxcon1(arr,n);

  

}