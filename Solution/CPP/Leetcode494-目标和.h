#include <vector>
using namespace std;
//一个朴素的01背包
//添加符号，一定有nagtive和positive两部分
//positive - nagtive = target
//pos + nag = sum
//pos = (sum + target) / 2
//就退化成一个简单的01背包问题了
//重量pos要装满，有几种方法
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        //Sum小于S，怎么凑都凑不够
        if(S > sum) return 0;
        //偶数不行
        if((sum + S) % 2 == 1) return 0;
        //int相加会不会溢出？
        int bagSize = (sum + S) / 2;
        vector<int> dp(bagSize + 1,0);
        dp[0] = 1;
        for(int i = 0;i < nums.size();i++){
            //背包至少要比当前遍历到的值大
            for(int j = bagSize;j >= nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[bagSize];
    }
};

#include <numeric>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(target > sum) return 0;
        if((sum + target) & 1) return 0;
        int pos = (sum + target) >> 1;
        int dp[pos + 1];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for(int i = 0;i < nums.size();i++){
            for(int j = pos;j >= nums[i];j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[pos];
    }
};

class Solution {
public:
    int cnt = 0;
    int target;
    int findTargetSumWays(vector<int>& nums, int target) {
        this -> target = target;
        dfs(nums,0,0);
        return cnt;
    }
    void dfs(vector<int>& nums,int idx,int sum){
        if(idx == nums.size()){
            if(sum == target){
                cnt++;
            }
            return;
        }
        dfs(nums,idx + 1,sum + nums[idx]);
        dfs(nums,idx + 1,sum - nums[idx]);
    }
};