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

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
