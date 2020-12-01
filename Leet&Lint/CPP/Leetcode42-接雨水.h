#include <vector>
using namespace std;
//爆力解法
//单独的考虑每一个节点能存多少的雨水高度，木桶短板原理，左右两边的最小高度减去当前高度
//注意包括当前的高度
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i = 1;i< n-1;i++){
            int lhs = 0,rhs = 0;
            for(int j = i;j < n;++j){
                rhs = max(rhs,height[j]);
            }

            for(int j = i;j >= 0;--j){
                lhs = max(lhs,height[j]);
            }

            res += min(lhs,rhs) - height[i];
        }
        return res;
    }
};

//更近一步，空间换时间。提前计算好左右的最大高度，放入数组中
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int res = 0;
        // 数组充当备忘录
        vector<int> lhs(n), rhs(n);
        // 初始化 base case
        lhs[0] = height[0];
        rhs[n - 1] = height[n - 1];
        // 从左向右计算 lhs
        for (int i = 1; i < n; i++)
            lhs[i] = max(height[i], lhs[i - 1]);
        // 从右向左计算 rhs
        for (int i = n - 2; i >= 0; i--) 
            rhs[i] = max(height[i], rhs[i + 1]);
        // 计算答案
        for (int i = 1; i < n - 1; i++) 
            res += min(lhs[i], rhs[i]) - height[i];
        return res;
    }
};
//双指针
/*
left_max：左边的最大值，它是从左往右遍历找到的
right_max：右边的最大值，它是从右往左遍历找到的
left：从左往右处理的当前下标
right：从右往左处理的当前下标

定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。

定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。（见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）

定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。

对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。 所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
*/
class Solution {
public:
    int trap(vector<int> &height){
        if(height.size() == 0) return 0;
        int n = height.size();
        int res = 0;
        int left = 0,right = n-1;
        int lhs = height[0],rhs = height[n-1];
        while(left <= right){
            lhs = max(lhs,height[left]);
            rhs = max(rhs,height[right]);
            if(lhs<rhs){
                res += lhs - height[left];
                left++;
            }else{
                res += rhs - height[right];
                right--;
            }
        }
        return res;
    }
};