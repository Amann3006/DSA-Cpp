#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main(){

 vector<int>arr;
 vector<int>arr1(6,12);

 arr.push_back(1);
 arr.push_back(0);
 arr.push_back(3);

 sort(arr.begin(),arr.end());
 

 for(unsigned int  i=0;  i<arr.size();i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
 for(  unsigned int i=0; i<arr.size();i++){
    cout<<arr1[i]<<" ";
 }
 cout<<endl;
 reverse(arr.begin(),arr.end());

 for(unsigned int  i=0;  i<arr.size();i++){
    cout<<arr[i]<<" ";
 }

}