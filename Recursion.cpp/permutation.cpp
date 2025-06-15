#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void permute(string str, int i=0){
    
    if(i==str.length()-1){
        cout<<str<<" ";
        return ;
    }
    for(int j=i; j<str.length(); j++){
    swap(str[i],str[j]);
    permute(str,i+1);
    swap(str[j],str[i]);
    }
}

int main(){
    string str;
 cin>>str; 
 int i=0;

 permute(str,i);
}