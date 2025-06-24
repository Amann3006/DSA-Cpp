#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int max(int arr[], int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int currsum = arr[i];
        int currmax = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            currsum += arr[index];
            currmax = max(currmax, currsum);
        }
        res = max(res, currmax);
    }
    return res;
}
//better solution
int normalmax(int arr[],int n){
   int res=arr[0],end=arr[0];
   for(int i=1; i<n; i++){
     end=max(arr[i],end+arr[i]);
     res=max(res,end);
   }
   return res;
}

int overmax(int arr[],int n){
    int maxnormal=normalmax(arr,n);

    if(maxnormal<0){
        return maxnormal;
    }

    int arrsum=0;
    for(int i=0; i<n; i++){
        arrsum+=arr[i];
        //covert all posvi to nega or vice versa
        arr[i]=-arr[i];
    }
    int maxcircular=arrsum+normalmax(arr,n);
    return max(maxnormal,maxcircular);
}

int main()
{
    int arr[] = {5,-2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max(arr, n)<<endl;
    cout<<overmax(arr,n);
}