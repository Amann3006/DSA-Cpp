#include <iostream>
using namespace std;

int main(){
    int a=3;
    int b=6;

    cout<<(a&b);
    cout<<(a|b);
    cout<<(a^b)<<endl;
    
    cout<<(a<<1)<<endl;
     cout<<(a<<2)<<endl;
     cout<<(b<<a)<<endl;
         a=33;
      cout<<(a>>1)<<endl;
       cout<<(a>>2)<<endl;
}