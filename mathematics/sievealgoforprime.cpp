#include <iostream>
#include<vector>
using namespace std;

bool isprime(int n){

    if(n==1){
       return false;
    }

    if(n==2 || n==3){
        return true;
    }


    if(n%2==0 || n%3==0){
        return false;
    }

    for(int i=5; i*i<=n; i=i+6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
}
return true;
}

//optime 
void sieve(int &n){
    vector<bool>isprime(n+1,true);

    for(int i=2; i<=n; i++){

        if(isprime[n]){

            for(int j=i*i; j<=n; j=j+i){
                isprime[j]=false;
            }

        }
    }
    for(int i=2; i<=n; i++){
        if(isprime[i]){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
   
    sieve(n);
}