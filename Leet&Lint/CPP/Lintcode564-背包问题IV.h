#include <vector>
using namespace std;
//计数背包
//背包问题的承重，一定时在状态里的
//最后一步，最后进背包的时那一个
//背包问题不限制次数
//类似于coins的拼法，最后一步能拼出来的话
//之前的最优再继续拼
//dp[i] = dp[i-a1] + dp[i-a2] + ....
class Solution {
public:
    int backPackVI(vector<int> &nums, int target) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> pai(target+1,0);
        vector<int> dp(target+1,0);
        //0重，有一种拼法
        dp[0] = 1;
        for(int i = 1;i <= target;++i){
            for(int j = 0;j<n;++j){
                if(i >= nums[j]){
                    dp[i] += dp[i - nums[j]];
                    // if(dp[i-nums[j]] > 0){
                    //     pai[i] = nums[j];
                    // }
                }
            }
        }
        return dp[target];
    }
};