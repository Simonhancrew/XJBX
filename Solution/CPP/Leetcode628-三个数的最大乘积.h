#include <vector>
#include <algorithm>
using namespace std;
//排序,要么是最大的三个数的乘积，要么有负数就两最小负数乘之后和最大的正数乘
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = nums[n-1] * nums[n-2] * nums[n-3];
        res = max(res,nums[0] * nums[1] * nums[n-1]);
        return res;
    }
};

//扫描找打最大的三个数，和最小的两个数
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //min1是最小的，min2是次小的
        int min1 = INT_MAX,min2 = INT_MAX;
        //max1最大
        int max1 = INT_MIN,max2 = INT_MIN,max3 = INT_MIN;
        for(auto num:nums){
            if(num < min1){
                min2 = min1;
                min1 = num;
            }else if(num < min2){
                min2 = num;
            }
        }
        for(auto num:nums){
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }else if(num > max2){
                max3 = max2;
                max2 = num;
            }else if(num > max3){
                max3 = num;
            }
        }
        return max(min1 * min2 * max1,max1 * max2 * max3);
    }
};