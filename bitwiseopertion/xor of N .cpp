#include <bits/stdc++.h>
using namespace std;

//brute force
int xor1(int n){
    int ans=0;
    for(int i=1; i<=n; i++){
        ans^=i;
    }
    return ans;
}

//optimal
/*n=1 ans=1  if(n%4==1) ret 1;
 n=2 ans=3    else if(n%4==2) ret n+1
 n=3 ans=0    else if(n%4==3) ret 0;
 n=4 ans=4    else ret n;
*/

int xor2(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    return n;
}
int main(){
    int n;
    cin>>n;
   cout<<xor1(n);
   cout<<xor2(n);
   int l=xor2(4-1 );
   int r=xor2(7);

   cout<<(l^r)<<endl;

}