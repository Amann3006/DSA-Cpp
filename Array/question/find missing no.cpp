#include<bits/stdc++.h>
using namespace std;

int main(){
    
    
    vector<int>arr={1,2,3,4,5,7};
    int n;
    cin>>n;
    int m=n-1;  

    int xor1=0;
    int xor2=0;

    for(int i=0; i<m; i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    cout<<(xor1^xor2);
      
} 