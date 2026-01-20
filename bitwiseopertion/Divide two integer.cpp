#include <bits/stdc++.h>
using namespace std;
//brute force t.c o(dividend)
void div1(int n,int m){
    int sum=0,cnt=0;

    while(sum+m<=n){
        cnt++;
        sum+=m;
    }
    cout<<cnt;
}

//better t.c(log n)^2
int div2(int n,int d){
     if(n==d){
        return 1;
     }
     bool sign=true;
     //-ve case
     if(n>=0 && d<0){
          sign=false;
     }
     if(n<0&& d>0){
        sign=false;
     }
     int ans=0;
      
     long divid=abs(n),divis=abs(d);

     while(divid>=divis){
        int cnt=0;

        while(divid>=(divis<<(cnt+1))){
            cnt++;
        }
        ans+=1<<cnt;
        divid=divid-(divis*(1<<cnt));
     }

     if(ans>=pow(2,31) && sign==true){
        return INT_MAX;
     }
     if(ans>=pow(2,31) && sign!=true){
        return INT_MIN;
     }
     return sign?ans:(-1*ans);
}
 //optimise
 int divide(int divi, int div) {
       
       if(divi==div){
        return 1;
       }
       if(divi==INT_MIN && div==-1){
        return INT_MAX;
       }
       return divi/div;
    }
int main(){
    int dividend,divisor;
    cin>>dividend>>divisor;

   div1(dividend,divisor);
   cout<<div2(dividend,divisor);
}