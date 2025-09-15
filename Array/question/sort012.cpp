#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int countz = 0, counto = 0, countt = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            countz++;
        } else if (nums[i] == 1) {
            counto++;
        } else if (nums[i] == 2) {
            countt++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (countz != 0) {
            nums[i] = 0;
            countz--;
        } else if (counto != 0) {
            nums[i] = 1;
            counto--;
        } else {
            nums[i] = 2;
            countt--;
        }
    }
}
//dutch national flag algorithm
void sort012(vector<int>&arr){
    int low=0,mid=0;
    int high=arr.size()-1;

    while(low<=mid){
        if(arr[low]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
       else if(arr[mid]==1){
        mid++;
       }
       else{
        swap(arr[mid],arr[high]);
        high--;
       }
     }
}
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);
    sort012(nums);
    for (int i = 0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
