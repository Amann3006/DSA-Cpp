#include<bits/stdc++.h>
using namespace std;
 //optimal
int longestcs( vector<int>&arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    int longest=1;
    unordered_set<int>st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int>arr={102,4,100,1,101,3,2,1,1};
     sort(arr.begin(),arr.end());
     int longest=1;
     int cnt=0;
    int lastsmaller=INT_MIN;
    int n=arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]-1==lastsmaller){
            cnt++;
            lastsmaller=arr[i];
        }
        else if(arr[i]!=lastsmaller){
            cnt=1;
            lastsmaller=arr[i];
        }
        longest=max(longest,cnt);
    }
    cout<<longest<<endl;
    cout<<longestcs(arr)<<endl;
}