#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& arr, int target) {
        int l=0;
        int h=(arr.size()*arr[0].size())-1;
       int m=arr[0].size();
        while(l<=h){
            int mid=l+(h-l)/2;
           int row=mid/m;
           int col=mid%m;

           if(arr[row][col]==target){
            return true;
           }
           else if(arr[row][col]<target){
            l=mid+1;
           }
           else{
            h=mid-1;
           }
        }
        return false;
    }

int main() {
    vector<vector<int>> arr = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    cout << "Search Result: " << (searchMatrix(arr, target) ? "Found" : "Not Found") << endl;

    return 0;
}
