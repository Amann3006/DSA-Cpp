#include <iostream>
using namespace std;


// optimize code
int pow2(int n){
    if(n==0){
        return 0;   //{ return (n&&((n&(n-1))==0)
    }

    return ((n&(n-1))==0);
}

 bool isPowerOfFour(int n) {
       if(n==0){
        return false;
       }
       
       return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) != 0);
}
//
 bool ispow2(int n){
    
    if(n==0){
        return true;
    }
    while(n!=1){
        if(n%2!=0){
            return false;
        }
        n=n/2;
    }
    return true;
 }  

int main(){
    
   int n;
    cin>>n;

    cout<<ispow2(n)<<endl;
    int ans =pow2(n);
    cout<<ans;
}