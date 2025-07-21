#include<iostream>
using namespace std;
//normal sloution 
void intersection(int a[],int b[],int n,int m){

    for(int i=0; i<n; i++){
        if(i>0 &&a[i]==a[i-1]){
            continue;
        }
        for(int j=0; j<m; j++){
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
        }
    }
}
//better 0(n)
void intersection1(int a[],int b[],int n,int m){
   int i=0;
   int j=0;
   while(i<n && j<m){
      if(i>0 && a[i]==a[i-1]){
        i++;
        continue;
      }
      else if(a[i]<b[j]){
        i++;
      }
      else if(a[i]>b[j]){
        j++;
      }
      else{
        cout<<a[i]<<" ";
        i++;
        j++;

      }
   }
}


int main() {
    int a[] = {1, 20, 20, 40, 60};
    int n = sizeof(a) / sizeof(a[0]);
    int b[]={2,20,20,20};
    int m=sizeof(b)/sizeof(b[0]);

    intersection(a,b,n,m);
    cout<<endl;
    intersection1(a,b,n,m);
    
    
   
    return 0;
}
