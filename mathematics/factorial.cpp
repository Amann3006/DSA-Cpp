#include <iostream>
using namespace std;

int fac(int n){
     if(n==0){
        return 1;
     }
    return n*fac(n-1);
}


int main(){
    int n;
    cin>>n;
    int res=1;
   int ans= fac(n);
    for(int i=2; i<=n; i++){
        res=res*i;
    }
    cout<< res<<endl;
    cout<<ans;
}


