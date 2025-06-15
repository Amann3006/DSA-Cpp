#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

//apporach 1 o(n2)
int largest(int*arr,int n){
    
    for(int i=0; i<n; i++){
        bool flag=true;

        for(int j=0; j<n; j++){
            if(arr[j]>arr[i]){
                flag=false;
                break;
            }
        }
        
        if(flag==true){
        return i;
    }
}
return -1;
    
}

//efficient apporach
int largest1(int arr[],int n){
    int res=0;
    for(int i=1; i<n; i++){
        if(arr[i]>arr[res]){
            res=i;
        }
        
    }
    return res;
}



int main(){
 int arr[]={5,8,20,23};
 int n=4;
 cout<<largest(arr,n)<<endl;
 cout<<largest1(arr,n)<<endl; 
 return 0;
}