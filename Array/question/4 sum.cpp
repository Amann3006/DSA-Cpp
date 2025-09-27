#include<bits/stdc++.h>
using namespace std;

//o(n3) 
vector<vector<int>>sum4(int n,vector<int>&arr){

   
   set<vector<int>>st;

    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum=arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];

                    if(sum==0){
                    vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
//0(n3)
vector<vector<int>>sum4p1(int target,vector<int>&arr){

        set<vector<int>>st;

    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int>hashset;
            for(int k=j+1; k<n; k++){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                int fourth=target-(sum);
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int>temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
        }
      }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
//0(n2*n)
vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;


    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        for(int j=i+1; j<n; j++){
          if(j!=i+1 && arr[j]==arr[j-1]){
            continue;
          }
          int k=j+1;
          int l=n-1;

          while(k<l){
            long long sum=arr[i];
            sum+=arr[j];
            sum+=arr[k];
            sum+=arr[l];

            if(sum<target){
                k++;
            }
            else if(sum>target){
                l--;
            }
            else{
                vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                ans.push_back(temp);
                k++;
                l--;
                while(k<l && arr[k]==arr[k-1]){
                    k++;
                }
                while(k<l && arr[l]==arr[l+1]){
                    l--;
                }
            }
          }
      }

    }
    
    return ans;
    }



int main(){

vector<int>arr={1,1,1,2,2,2,3,3,3,4,4,4,5,5};
     int t;
     cin>>t;

vector<vector<int>> res = fourSum( arr,t);

    for(auto& trip : res) {
        for(int x : trip) cout << x << " ";
        cout << endl;
    }


}