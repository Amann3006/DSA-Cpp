#include<iostream>
using namespace std;

int lastocc(int arr[],int x,int n){
      int s=0, e=n-1;
    
         while(s<=e){
        int mid=s+(e-s)/2;

         if(arr[mid]>x){
           e=mid-1;  //for iterative just write e=mid-1;
        }
        else if(arr[mid]<x){
           s=mid+1; //for iterative just write s=mid+1;
        }

        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1]){
                return mid;
            }
            else{
                s=mid+1;  //for  first iterative just write e=mid-1 and for last s=mid+1;
            }
        }
    }
    return -1;
    
}

int firstocc(int arr[],int x,int n){
    
   
        int s=0, e=n-1;
        while(s<=e){
        int mid=s+(e-s)/2;

         if(arr[mid]>x){
           e=mid-1; //for iterative just write e=mid-1;
        }
        else if(arr[mid]<x){
           s=mid+1; //for iterative just write s=mid+1;
        }

        else{
            if(mid==0 || arr[mid]!=arr[mid-1]){
                return mid;
            }
            else{
                e=mid-1; //for  first iterative just write e=mid-1 and for last s=mid+1;
            }
        }
    }
    return -1;
    
}


int countocc(int arr[],int n,int x){
   int first=firstocc(arr,x,n);

   if(first==-1){
    return 0;
   }

   return (lastocc(arr,x,n)-first+1);
}





int main(){
    int arr[]={10,20,30,30,50,50,60};
    int x;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
   cout<< countocc(arr,n,x);
}

