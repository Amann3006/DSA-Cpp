#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to get the Kth largest element 
    int kthLargestElement(vector<int>& nums, int k) {
        
        // Min-heap data structure
        priority_queue <int, vector<int>, greater<int>> pq;
        
        // Add the first K elements in the Min-heap
        for(int i = 0; i < k; i++) pq.push(nums[i]);
        
        // Process the rest of the elements 
        for(int i = k; i < nums.size(); i++) {
            // Check if a new larger element is found
            if(nums[i] > pq.top()) {
                
                pq.pop(); // remove the smallest from the min-heap
                
                // Add the current element to the min-heap
                pq.push(nums[i]); 
            }
        }
        
        return pq.top(); // Return the kth largest element 
    }
};


// Driver code
int main() {
    vector<int> nums = {-5, 4, 1, 2, -3};
    int k = 5;

    // Creating an object of the Solution class
    Solution sol;

    // Function call to get the Kth largest element 
    int ans = sol.kthLargestElement(nums, k);

    // Output array
    cout << "The Kth largest element in the array is: " << ans << endl;

    return 0;
}