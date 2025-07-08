#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//0(n2)
int solve1(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}
//o(nlogn)
 int solve2(vector<int>&arr){
  sort(arr.begin(),arr.end());
   int n=arr.size();
  for(int i=0; i<n-1; i++){
    if(arr[i]==arr[i+1]){
        return arr[i];
    }
  }
return -1;
}

//o(n) sco(n);
int solve3(int arr[],int n){
    vector<bool>visted(n-1,false);
    
    for(int i=0; i<n; i++){
        if(visted[arr[i]]){
            return arr[i];
        }

        visted[arr[i]]=true;
    }
    return -1;
}


int solve4(int arr[]){
  //this case for only when smallest elem in array is 1 
 //for array with 0 we add 1 all step
    int slow=arr[0];  //arr[0]+1;
    int fast=arr[0];   //arr[0]+1

    do{
        slow=arr[slow];    //arr[slow]+     
        fast=arr[arr[fast]]; //arr[arr[fast]+1]+1

    }while(slow!=fast);

    slow=arr[0];  //arr[0]+1;
     
    while(slow!=fast){
        slow=arr[slow]; //arr[slow]+1
        fast=arr[fast]; // arr[fast]+1;
    }
    
    return slow;
}


int main(){
    int arr[]={1,3,2,4,6,5,7,3};  
    vector<int>arr1={1,3,2,4,6,5,7,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<solve1(arr,n)<<endl;
    cout<<solve2(arr1)<<endl;
    cout<<solve3(arr,n);
   
}