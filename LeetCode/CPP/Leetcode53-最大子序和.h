#include <vector>
using namespace std;
class Solution {
/* 我们定义一个操作 get(a, l, r) 表示查询 aa 序列 [l, r][l,r] 区间内的最大子段和，
那么最终我们要求的答案就是 get(nums, 0, nums.size() - 1)。如何分治实现这个操作呢？对于一个区间 [l, r][l,r]，
我们取 m =

对区间 [l, m][l,m] 和 [m + 1, r][m+1,r] 分治求解。
当递归逐层深入直到区间长度缩小为 11 的时候，递归「开始回升」。
这个时候我们考虑如何通过 [l, m][l,m] 区间的信息和 [m + 1, r][m+1,r] 区间的信息合并成区间 [l, r][l,r] 的信息。
最关键的两个问题是：
我们要维护区间的哪些信息呢？
我们如何合并这些信息呢？
对于一个区间 [l, r][l,r]，我们可以维护四个量：

lSum 表示 [l, r][l,r] 内以 ll 为左端点的最大子段和
rSum 表示 [l, r][l,r] 内以 rr 为右端点的最大子段和
mSum 表示 [l, r][l,r] 内的最大子段和
iSum 表示 [l, r][l,r] 的区间和
以下简称 [l, m][l,m] 为 [l, r][l,r] 的「左子区间」，[m + 1, r][m+1,r] 为 [l, r][l,r] 的「右子区间」。
我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 [l, r][l,r] 的信息）？

对于长度为1的区间，四个值的和都等于ai，对于长度大于1的区间：

首先最好维护的是 iSum，区间 [l, r][l,r] 的 iSum 就等于「左子区间」的 iSum 加上「右子区间」的 iSum。
对于 [l, r][l,r] 的 lSum，存在两种可能，它要么等于「左子区间」的 lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
对于 [l, r][l,r] 的 rSum，同理，它要么等于「右子区间」的 rSum，要么等于「右子区间」的 iSum 加上「左子区间」的 rSum，二者取大。
当计算好上面的三个量之后，就很好计算 [l, r][l,r] 的 mSum 了。
我们可以考虑 [l, r][l,r] 的 mSum 对应的区间是否跨越 mm——它可能不跨越 mm，
也就是说 [l, r][l,r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的 mSum 中的一个；
它也可能跨越 mm，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和。三者取大。
*/
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) return (Status){a[l], a[l], a[l], a[l]};
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

//贪心，有一个序列和为负数的话这个序列之后就没用了，肯定对后面的序列是副作用的
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int result = INT32_MIN;
        int count = 0; 
        for(int i = 0;i < nums.size();++i){
            count += nums[i];
            if(count > result){
                result = count;
            }
            if(count <= 0){
                count = 0;
            }
        }
        return result;
    }
};

//动态规划,序列型，也可以算是坐标型
//最后一步，在i位置之前的最大自序和,dp更新，要么前i-1位置的子序和加上nums[i]，否则前面的就是负数，nums[i]就是现在的解
//dp[i] = max(dp[i-1] + nums[i],nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0); // dp[i]表示包括i之前的最大连续子序列和
        int dp1 = nums[0];
        int dp2 = INT_MIN;
        int result = dp1;
        for (int i = 1; i < nums.size(); i++) {
            dp2 = max(dp1 + nums[i], nums[i]); // 状态转移公式
            if (dp2 > result) result = dp2;
            dp1 = dp2; // result 保存dp[i]的最大值
        }
        return result;
    }
};