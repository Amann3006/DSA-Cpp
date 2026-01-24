#include <bits/stdc++.h>
using namespace std;

// t.c(n)
void primeFactorsNaive(long long n)
{
    for(long long i = 2; i <= n; i++){
        while(n % i == 0){
            cout << i << " ";
            n /= i;
        }
    }
}

// t.c(sqrt n)
void primeFactorsSqrt(long long n)
{
    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 1) cout << n;
}

//t.c(sqrt n*log n)
void primeFactorsSqrtLog(long long n)
{
    
    while(n % 2 == 0){
        cout << 2 << " ";
        n /= 2;
    }

    // only odd numbers
    for(long long i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            cout << i << " ";
            n /= i;
        }
    }

    // remaining prime
    if(n > 1) cout << n;
}


int main()
{
    long long n;
    cin >> n;

    cout << "\nNaive O(n): ";
    primeFactorsNaive(n);
    
    cout << "\nOptimized sqrt(n): ";
    primeFactorsSqrt(n);

    cout << "\nSqrt(n) * log n : ";
    primeFactorsSqrtLog(n);

    return 0;
}
