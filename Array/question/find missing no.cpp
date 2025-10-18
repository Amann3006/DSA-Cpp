#include<bits/stdc++.h>
using namespace std;
  
  vector<int>solve(vector<int>&arr){
         int n=arr.size();
      
    int hash[n+1]={0};

    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    int missing=-1,repeat=-1;

    for(int i=0; i<n; i++){
        if(hash[i]==2){
            repeat=i;
        }
        else if(hash[i]==0){
            missing=i;
        }
        
        if(missing==-1&&repeat==-1){
            break;
        } 
        
    }
    return{missing,repeat};
  }
  
  //optmal 1 maths
  vector<int>solve1(vector<int>&arr){
    long long n=arr.size();
    // s-Sn=x-y
    //s2-s2n
    long long sn=(n*(n+1))/2;
    long long sn2=(n*(n+1)*(2*n+1))/6;
    long long s=0,s2=0;

    for(int i=0; i<n; i++){
        s+=arr[i];
        s2+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1=s-sn; //x-y
    long long val2=s2-sn2;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=x-val1;

    return {int(x),int(y)};
  }
int main(){
    
    
    vector<int>arr={1,2,3,4,5,7,1};
    vector<int>ans=solve1(arr);

    for(int i=0; i<2; i++){
        cout<<ans[i]<<" ";
    }
      
} 