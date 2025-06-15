#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int largest(int arr[],int n){
     
    int res=0;
    for(int i=1; i<n; i++){
       if(arr[i]>arr[res]){
        res=i;
       }
    }
    return res;

}

int secondlargest(int arr[],int n){
      int larg=largest(arr,n);

      int res=-1;

      for(int i=0; i<n; i++){
        if(arr[i]!=arr[larg]){
            if(res==-1){
                res=i;
            }
            else if(arr[i]>arr[res]){
                  res=i;
            }
        }
      }
      return res;
      
} 

//efficient apprach

int seclargest(int arr[],int n){
  int scelarg=-1,larg=0;
  for(int i=1; i<n; i++){
    if(arr[i]>arr[larg]){
        scelarg=larg;
        larg=i;
    }
    else if(arr[i]!=arr[larg]){
        if(scelarg==-1|| arr[i]>arr[scelarg]){
            scelarg=i;
        }
    }
  }
  return scelarg;
}

int main(){
    int arr[]={20,3,20,20};
    int n=4;

    //cout<<secondlargest(arr,n);
    cout<<seclargest(arr,n);

    
}