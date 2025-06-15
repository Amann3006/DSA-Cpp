#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


void subset(string str,string curr=" ", signed int i=0){
     if(i==str.length()){
        cout<<curr<<" ";
        return ;
     }
    //exclude
     subset(str,curr,i+1);
     //include
     subset(str,curr+str[i],i+1);

}


int main(){

 string str;
 cin>>str;

 string curr;
 
 int i=0;

 subset(str,curr,i);
 


}