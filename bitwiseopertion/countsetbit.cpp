#include <iostream>
using namespace std;

//optimize solution (look up soultion)
 
int tbl[256];
void initi(){
    tbl[0]=0;
    for(int i=1; i<256; i++){
      tbl[i]=tbl[i&(i-1)]+1; 
    }

}

int count3(int n){

    return tbl[n&255]+tbl[(n>>8)&255]+tbl[(n>>16)&255]+tbl[n>>255];
    
}




//brian kerningam algo 

int count2(int n){

    int res=0;
    while(n>0){
      n=n&(n-1);
      res=res+1;
    }
    return res;
}
//efficient apporach
int count1(int n){

    int count1=0;
    while(n>0){
        count1=count1+(n&1);
         n=n>>1;
    }
    return count1;
}
    
int count(int n){

    int count1=0;
    while(n>0){
        if((n&1)!=0){
            count1++;
        }
         n=n>>1;
    }
    return count1;
}
int main(){

    int n;
    cin>>n;

   int ans = count(n);

   cout<<ans;

}