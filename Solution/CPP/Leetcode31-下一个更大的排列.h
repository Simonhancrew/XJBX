#include <vector>
#include <algorithm>
//我们找到这样一个不符合规则的数对，让大数尽可能的小，小的数尽可能的大
//代码上，我们从后往前的找到第一个破坏规则的数。
//然后把他和他后面第一个比他大的数交换
//注意考虑相等的数的情况
//交换之后，我们把后部分的有序区按照升序排列，这样变化就会尽可能的小
//如果遍历结束，全部是符合规则的，直接reverse整个数组
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //至少两个数
        int i = nums.size() - 2;
        //注意考虑==的情况，不调整
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            //找到第一个可调整的数
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            //注意不调整相等的情况
            while (j >= i+1 && nums[i] >= nums[j]) {
                //让另一个调整的数尽可能的小
                j--;
            }
            swap(nums[i], nums[j]);
        }
        //让i之后的部分有序
        reverse(nums.begin() + i + 1, nums.end());
    }
};