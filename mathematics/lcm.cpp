#include <iostream>
using namespace std;


//2 apporac


int gcd(int a,int b){
    if(b==0){
        return a;

    }
        return gcd(b,a%b);
    
}

int lcm(int a, int b){

    return (a*b)/gcd(a,b);
}
  
  
int main(){

    int a,b;
    cin>>a>>b;

    int res=0;

    if(a>b){
        res=a;
    }
    else{
        res=b;
    }

    while(true){
        if(res%a==0 && res%b==0){
            return res;
        }
        else{
            res++;
        }
    }
    cout<<res<<endl;

    int ans =lcm(a,b);
    cout<<ans;
     
}
