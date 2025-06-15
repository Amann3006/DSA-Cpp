#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int power(int x,int n){

    int res=1;
    for(int i=0; i<n; i++){
        res=res*x;
    }
    return res;
}

//efficeibnt solution

void power1(int x,int n){
     
    if(n==0){
        return ;
    }
    if(n%2==0){
        power(x,n/2)* power(x,n/2);
    }
    else{
        power(x,n-1)*x;
    } 
}


int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;

    int ans=power(x,n);

    int y=pow(n,x);
    cout<<y;
    cout<<ans;
    power1(x,n);
}