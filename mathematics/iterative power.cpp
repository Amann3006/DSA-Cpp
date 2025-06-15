#include <iostream>
using namespace std;

int power(int x, int n) {
   long long  int res = 1;
    while (n > 0) {
        if (n&1) {
            // If the current bit is 1
            res = res * x;
        }
        // Square the base
        x = x * x;
        // Divide the exponent by 2
        n = n>>1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    int ans = power(x, n);
    cout << ans;
}
