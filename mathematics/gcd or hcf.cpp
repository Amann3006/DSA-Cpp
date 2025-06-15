#include <iostream>
using namespace std;

//apporach 2 - euclieden algo

int gcd(int a,int b){

    while(a!=b){
        if(a>b){
            a=a-b;

        }
        else{
            b=b-a;
        }
    }
    return a;
}

//optimize 
int gcd2(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd2(b,a%b);
    }
}


int main(){
   
    int a,b;
    cin>>a>>b;

    int res=0;

   if(a>b){
    res=b;
   }
   else{
    res=a;
   }

   while(res>0){

    if(a%res==0&&b%res==0){
        break;
    }
    else{
    res--;
    }
   }
   
   cout<<res<<endl;
   int ans= gcd(a,b);
   int ans2=gcd2(a,b);
   cout<<ans<<endl;
   cout<<ans2<<endl;

}