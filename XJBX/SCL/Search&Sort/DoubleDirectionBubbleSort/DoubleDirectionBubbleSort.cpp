#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PRINTARRY(NUMS) do{\
    for(auto num:NUMS){\
        cout << num<< ' ';\
    }\
    cout << endl; \
}while(0)

void DoubleDirectionBubbleSort(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }
    int left = 0, right = n - 1;
    bool flag;
    while (left < right) {
        flag = false;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                flag = true;
            }
        }
        --right;
        for (int i = right; i > left; i--) {
            if (nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
                flag = true;
            }
        }
        ++left;
        if (!flag) {
            return;
        }
    }
}


int main() {
    vector<int> nums = { 3,2,1,2,4,56,7,4,2,332 };
    DoubleDirectionBubbleSort(nums);
    PRINTARRY(nums);
    return 0;
}