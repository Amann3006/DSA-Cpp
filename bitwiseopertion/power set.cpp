 #include<iostream>
 #include<string.h>
 using namespace std;
   
   //tc(n*2^n)
   void printpower(string s){
    int n =s.length();
    int psize=(1<<n);

    for(int i=0;  i<psize-1; i++){ ///->2^n
        for(int j=0; j<n; j++){//->n
            if((i&(1<<j))!=0){

                cout<<s[i]<<endl;;
                
            }
        }
    }


   }
 


 int main(){

    string s;
    cin>>s;
       
    printpower(s);
 }