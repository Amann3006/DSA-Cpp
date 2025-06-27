#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int maxappear(int arr[],int range[],int n){
    int freq[100]={0};

    for(int i=0; i<n; i++){
        for(int j=arr[i]; j<=range[i]; j++){
             freq[j]+=1;
        }
    }

    int res=0; 
    for(int i=1; i<100; i++){
        if(freq[i]>freq[res]){
            res=i;
        }

    }
    return res;
}

//o(n+max)

int maxappear1(int arr[],int range[],int n){
    int freq[101]={0};

    for(int i=0; i<n; i++){
       freq[arr[i]]++;
       freq[range[i]+1]--;
    }

    int res=0; 
    for(int i=1; i<100; i++){
        //prefix sum 
        freq[i]=freq[i-1]+freq[i];
        if(freq[i]>freq[res]){
            res=i;
        }

    }
    return res;
}




int main(){
    int arr[]={1,2,4};
    int range[]={4,5,7};
    int n = sizeof(arr) / sizeof(arr[0]);
     
    cout<<maxappear(arr,range,n)<<endl;
    cout<<maxappear1(arr,range,n);
}