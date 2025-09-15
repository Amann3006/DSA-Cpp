#include<bits/stdc++.h>
using namespace std;


//optimal
vector<int> sortedarray(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();
   
    int i=0;
    int j=0;

    vector<int>unionarr;
    while(i<n1 && j<n2){
        if(a[i]<=b[i]){
            if(unionarr.size()==0 || unionarr.back()!=a[i])
            {
               unionarr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionarr.size()==0 || unionarr.back()!=b[j])
            {
               unionarr.push_back(b[j]);

            }
            j++;
         }
        }
        return unionarr;
}

//brute force
vector<int> sortedarray(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();

    set<int>st;

    for(int i=0; i<n1; i++){
        st.insert(a[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(b[i]);
    }

    vector<int>temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}

int main(){
    vector<int>arr={1,1,2,3,4,5};
    vector<int>arr2={2,3,4,4,5,6};
   

    vector<int> result = sortedarray(arr, arr2);

    // Print result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
   
} 