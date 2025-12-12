#include <bits/stdc++.h>
using namespace std;

double power(double x, long n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;

    if (n % 2 == 0) 
        return power(x * x, n / 2);

    return x * power(x, n - 1);
}

double myPow(double x, int n) {
    long num = n;

    if (num < 0) 
        return 1.0 / power(x, -num);

    return power(x, num);
}

int main() {
    double x = 2.0;
    int n = 10;

    double result = myPow(x, n);

    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
