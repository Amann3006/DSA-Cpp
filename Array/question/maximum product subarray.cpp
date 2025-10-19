
#include <bits/stdc++.h>
using namespace std;

int maxiproduct(vector<int>&a,int n){
    int preffix=1,suffix=1;
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        if(preffix==0){
            preffix=1;
        }
        if(suffix==0){
            suffix=0;
        }
        preffix=preffix*a[i];
        suffix=suffix*a[n-i-1];
        ans=max(ans,max(suffix,preffix));
    }
    return ans;
}

int main()
{
    vector<int> a = {-2,3,4,-1,0,-2,3,1,4,0,4,6,-4};
    int n=a.size();
    cout<<maxiproduct(a,n);
    
}
