#include <vector>
using namespace std;
//计数型背包
//bool变成计数，求并集变成加法
//dp[i][w]前i个数，能拼成w重量的方法数
class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        //前0个物品拼出0只有一种方法
        dp[0][0] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= target;++j){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]){
                    dp[i][j] += dp[i-1][j - nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};

//滚动数组优化之后还可以优化
//实际中，可以在原数组上构造，只开一个一维数组
//需要考虑不要覆盖没用过的，就从尾部开始重覆盖
class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp(target+1,0);
        //前0个物品拼出0只有一种方法
        dp[0] = 1;
        for(int i = 1;i <= n;++i){
            //这个数组从尾部开始重新覆盖，之前的数据和尾部无关
            for(int j = target;j >= 0;--j){
                //dp[j]+dp[j - nums[i-1]] -> dp[j]
                if(j >= nums[i-1]){
                    //dp`[j]
                    //覆盖dp[j]
                    dp[j] += dp[j - nums[i-1]];
                }
            }
        }
        return dp[target];
    }
};