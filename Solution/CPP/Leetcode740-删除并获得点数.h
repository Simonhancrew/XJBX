#include <vector>
#include <algorithm>
using namespace std;
//同一个点数的全部加起来（因为能删除这个点数就说明能删除这个点全部的点数）；之后创建新数组，按照点数。
//下面就和打家劫舍一样的线性dp
class Solution {
public:
    int line(vector<int> const &nums){
        int n = nums.size();
        vector<int> dp(n + 1,0);
        dp[1] = nums[0],dp[2] = max(nums[0],nums[1]);
        for(int i = 3;i <= n;i++){
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i - 1]);
        }   
        return dp[n];
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxele = *max_element(nums.begin(),nums.end());
        vector<int> sum(maxele + 1,0);
        for(auto num:nums){
            sum[num] += num;
        }
        return line(sum);
    }
};

//滚动优化
class Solution {
public:
    int line(vector<int> const &nums){
        int n = nums.size();
        int old  = nums[0],now = max(nums[0],nums[1]);
        for(int i = 3;i <= n;i++){
            int tmp = max(now,old + nums[i - 1]);
            old = now;
            now = tmp;
        }   
        return now;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxele = *max_element(nums.begin(),nums.end());
        vector<int> sum(maxele + 1,0);
        for(auto num:nums){
            sum[num] += num;
        }
        return line(sum);
    }
};