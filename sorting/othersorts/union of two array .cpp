#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
//normal sloution 
void unionoftwo(int a[],int b[],int n,int m){
   int c[m+n];
   for(int i=0; i<n; i++){
    c[i]=a[i];
   }
   for(int i=0; i<m; i++){
    c[n+i]=b[i];
   }

   sort(c,c+m+n);

   for(int i=0; i<m+n; i++){
       if(i==0 || c[i]!=c[i-1]){
        cout<<c[i]<<" ";
       }
   }

    
}
//better 0(n)
void unionoftwo1(int a[],int b[],int n,int m){
    int i=0; 
    int j=0;
    while(i<n && j<m){
        if(i>0 && a[i]==a[i-1]){
            i++;
            continue;
        }
        if(j>0 && b[j]==b[j-1]){
            j++;
            continue;
        }
        else if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n){
        if(i>0 && a[i]!=a[i-1]){
           cout<<a[i]<<" ";
           i++;
        }
    }
    while(j<m){
        if(j>0 && b[j]!=b[j-1]){
            cout<<b[j]<<" ";
            j++;
        }
    }
}


int main() {
    int a[] = {10,20,20};
    int n = sizeof(a) / sizeof(a[0]);
    int b[]={5,20,40,40};
    int m=sizeof(b)/sizeof(b[0]);

    unionoftwo(a,b,n,m);
    cout<<endl;
    unionoftwo1(a,b,n,m);
    
    
   
    return 0;
}
