#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
//动态规划，等分数组，一半一半
//dp[i][j] 0-i这些下标的数能不能凑成和为j的数
//j最大为target
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //特殊情况，只有1个或更少元素的时候无法分割
        if(n<2) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxnum = *max_element(nums.begin(),nums.end());
        //如果和为奇数，则不能分为两份
        if(sum & 1){
            return false;
        }
        int target = sum/2;
        if(maxnum > target){
            return false;
        }
        //[0,target]，0-i这些数，能不能凑成和为j的数
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        //选择和为0，任意i都可以，等价于不选
        for(int i =0;i<n;i++){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = true;
        for(int i = 1;i<n;i++){
            int num = nums[i];
            for(int j = 1;j<=target;j++){
                //当前的值比j小的话，num是可选的
                if(j>num){
                    //选不选nums[i]都可以，结果是一个或的关系
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }else{
                    //不能选nums[i]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};