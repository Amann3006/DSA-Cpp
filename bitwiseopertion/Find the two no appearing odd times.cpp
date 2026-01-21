#include <bits/stdc++.h>
using namespace std;


   //brute force t.c(n) s.c (n)
    vector<int> singleNumber(vector<int>& nums){
        
        
        vector<int> ans;
        
     
        unordered_map <int, int> mpp;
        
        
        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        
       
        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }   
        
       
        sort(ans.begin(), ans.end());
        return ans;
    }
   //t.c(n);
    vector<int>xorapporach(vector<int>&nums){
        int n=nums.size();
        int x=0;

        for(int i=0; i<n; i++){
            x=x^nums[i];
        }
         //x=3^5=110=6
        //rightmost set bits 
        int rightb=(x&x-1)^x; 
        int ans1=0,ans2=0;

        for(int i=0; i<n; i++){
            if(nums[i]&rightb){     //eg 3=011
                 ans1=ans1^nums[i];                   // &  6=110
                                    // =010 !=0 hence go to ans1
            }
            else{
                ans2=ans2^nums[i];
            }
        }
        return {ans1,ans2};
    }


int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    
   
    vector<int> ans = singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    vector<int>ans2= xorapporach(nums);
    cout << "The single numbers in given array are: " << ans2[0] << " and " << ans2[1];

    return 0;
}