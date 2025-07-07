#include <iostream>
#include <climits>
using namespace std;

double findMedian(const int nums[], int n) {
    if (n % 2 == 0) {
        return (double)(nums[n / 2 - 1] + nums[n / 2]) / 2;
    } else {
        return (double)nums[n / 2];
    }
}

double findMedianSortedArrays(int nums1[], int n1, int nums2[], int n2) {
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, n2, nums1, n1);
    }

    int s = 0, e = n1;

    while (s <= e) {
        int i1 = (s + e) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
        int min1 = (i1 == n1) ? INT_MAX : nums1[i1];
        int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
        int min2 = (i2 == n2) ? INT_MAX : nums2[i2];

        if (max1 <= min2 && max2 <= min1) {
            if ((n1 + n2) % 2 == 0) {
                return (double)(max(max1, max2) + min(min1, min2)) / 2;
            } else {
                return (double)max(max1, max2);
            }
        } else if (max1 > min2) {
            e = i1 - 1;
        } else {
            s = i1 + 1;
        }
    }

    return 0.0;
}

int main() {
    int nums1[] = {1, 2, 3, 5, 6};
    int nums2[] = {4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    
    cout << "Median: " << findMedianSortedArrays(nums1, n1, nums2, n2) << endl;
    
    return 0;
}
