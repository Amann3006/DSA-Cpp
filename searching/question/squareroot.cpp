#include<iostream>
using namespace std;

int squareroot(int x){
   int i=1;
   while(i*i<=x){
    i++;
   }
   return (i-1);
}

//efficient solution 
int sqroot(int x){
    int s=1;
    int e=x;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;
        int squ=mid*mid;
        if(squ==x){
           return mid;
        }

        else if(squ>x){
            e=mid-1;
        }
        else{
            s=mid+1;
            ans=mid;
        }
    }
    return ans;
}


int main(){
   
    
    int x;
    cin>>x;
   cout<< squareroot(x)<<endl;
   cout<<sqroot(x);
}
