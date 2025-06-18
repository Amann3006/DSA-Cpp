 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//efficient solution
int maxProfit2(vector<int>& prices){
    int profit=0;

        for(int i=1; i<prices.size(); i++){
            if (prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;
    }

// Example usage
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
 
    cout<< maxProfit2(prices) << endl;
    return 0;
}
