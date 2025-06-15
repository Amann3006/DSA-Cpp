#include <iostream>
using namespace std;

int fun(int n){

    if(n==1){
        return 0;
    }
    return 1+fun(n/2);

}

void dectobinary(int n){
    
    if(n==0){
        return ;
    }
  
    dectobinary(n/2);
    int sum=n%2;
    cout<<sum<<" ";
    
}

int main(){
    int n;
    cin>>n;

    dectobinary(n);
    cout<<endl;
    int ans=fun(n);

    cout<<ans;
}