#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<int>arr={10,20,5,7};
    int n=arr.size();
    sort(arr.begin(),arr.end());

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    sort(arr.begin(),arr.end(),greater<int>());
    cout<<endl;
   
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}
