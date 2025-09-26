#include<bits/stdc++.h>
using namespace std;




//o(n3) 
vector<vector<int>>triplet(int n,vector<int>&arr){

   
   set<vector<int>>st;

    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

//0(n2)
vector<vector<int>>triplet2(int n,vector<int>&arr){

   
   set<vector<int>>st;

    
    for(int i=0; i<n; i++){
        set<int>hashset;
        for(int j=i+1; j<n; j++){
           int third=-(arr[i]+arr[j]);
           if(hashset.find(third)!=hashset.end()){
              vector<int>temp={arr[i],arr[j],third};
              sort(temp.begin(),temp.end());
              st.insert(temp);
           }
           hashset.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
//o(nlogn)+o(n*m);

vector<vector<int>>triplet3(int n,vector<int>&arr){

 

    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                j++;
            }
            else if (sum<0){
                k--;
            }
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]){
                    j++;
                }
                while(j<k && arr[k]==arr[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}


int main(){

vector<int>arr={-1,0,1,2,-1,-4};
     int n = arr.size();

vector<vector<int>> res = triplet3(n, arr);

    for(auto& trip : res) {
        for(int x : trip) cout << x << " ";
        cout << endl;
    }


}