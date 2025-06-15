#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


 


/*
int ropecut(int n,int a, int b,int c){
 
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;  
    }
    int resA = ropecut(n - a, a, b, c);
    int resB = ropecut(n - b, a, b, c);
    int resC = ropecut(n - c, a, b, c);

    int maxRes = max({resA, resB, resC});

    if (maxRes == -1) return -1;

    return maxRes + 1;

}
int sumofdigit(int n){
    if(n==0){
        return 0;
    }
    
    return sumofdigit(n/10)+n%10;
}
bool ispalindrome(string str,int s ,int e){
    if(s>=e){
        return true;
    }

    return(str[s]==str[e])&&ispalindrome(str,s+1,e-1);
}
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
int fibo(int n){
    if(n<=1){
        return n;
    }
    
    return fibo(n-1)+fibo(n-2);
}
int fact(int n){

    if(n==0||n==1){
        return 1;
    }

    return n*fact(n-1);
}
*/
int main(){
   // int n;
    //cin>>n;
    //int a,b,c;
    //cin>>a>>b>>c;

   string a;
    cin>>a;
   // int s=0;
   // int e=a.length()-1;
   // cout<<fact(n)<<endl;
   // cout<<fibo(n);
   //cout<<sum((n));
 // cout<<ispalindrome(a,s,e);
 //cout<<sumofdigit(n)<<" "<<endl;
 //cout<<ropecut(n,a,b,c);
   
}