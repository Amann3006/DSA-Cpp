#include<iostream>
using namespace std;

int fun(int mid,int n,int m){
      long long ans=1;
      for(int i=1; i<=n; i++){
        ans=ans*mid;
        if(ans>m) return 2; 
      }
      if(ans==m) return 1;
      return 0;
}

//efficient solution 
int nthroot(int n,int m){
    int s=1;
    int e=m;
    
    while(s<=e){
        int mid=(s+e)/2;
        int midn=fun(mid,n,m);
        if(midn==1){
           return mid;
        }

        else if(midn==0){
            s=mid+1;
        }
        else{
            e=mid-1;
            
        }
    }
    return -1;
}


int main(){
   
    
    int n,m;
    cin>>n>>m;
   cout<< nthroot(n,m);
}
