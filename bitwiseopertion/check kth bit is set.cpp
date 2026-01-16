#include <iostream>
using namespace std;

// LEFT SHIFT
void isset2(int n,int k){
    int x = 1 << (k-1);
    if(n & x) cout<<"yes";
    else cout<<"no";
}

// RIGHT SHIFT
void isset3(int n,int k){
    if(((n>>(k-1)) & 1) != 0)
        cout<<"yes";
    else
        cout<<"no";
}

// DIVIDE METHOD
void isset1(int n,int k){
    for(int i=0;i<k-1;i++)
        n = n/2;

    if(n & 1)
        cout<<"yes";
    else
        cout<<"no";
}


void isset(int n,int k){
    int x = 1;
    for(int i=0;i<(k-1);i++)
        x = x*2;

    if(n & x)
        cout<<"yes";
    else
        cout<<"no";
}

int main(){
    int n,k;
    cin>>n>>k;

    isset(n,k);
    cout<<endl;
    isset1(n,k);
    cout<<endl;
    isset2(n,k);
    cout<<endl;
    isset3(n,k);
}
