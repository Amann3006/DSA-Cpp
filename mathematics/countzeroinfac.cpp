#include <iostream>
using namespace std;


//2 approch

int countz(int n){

    int count=0;
    for(int i=5; i<=n; i=i*5){
        count=count+n/i;
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    int res=1;
   
    for(int i=2; i<=n; i++){
        res=res*i;
    }

    int count=0;
    while(res%10==0){
        res=res/10;
        count++;
    }
    int ans=countz(n);
   // cout<< res<<endl;
   // cout<<count<<endl;
    cout<<ans;
   
}


