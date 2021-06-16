#include <vector>
using namespace std;
//玩家和之差大于等于0则1胜利
//从start开始到end结束去递归。从两个位置各当前玩家选择最大的结果
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;//正的选正的最大，负的选负的最小
    }
};


//动态规划
//dp[i][j]表示当前数组可以选的位（i，j）,此时两数之差的最大值
class Solution2 {
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n,vector<int>(n));
        for(int i =0;i<n;i++){
            dp[i][i] = nums[i];
        }
        for(int i = n-2;i>=0;i--){
            for(int j =i+1;j<n;j++){
                //i<j,可以选nums[i]或是nums[j]，然后另一玩家在剩下的数组中选
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        //保证先手能赢就可以
        return dp[0][n-1]>=0;
    }
};
#include <numeric>
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int dp[n][n];
        for(int len = 1;len <= n;len++){
            for(int i = 0;i + len - 1 < n;i++){
                int j = i + len - 1;
                if(i == j) dp[i][j] = nums[i];
                else{
                    dp[i][j] = max(nums[i] - dp[i + 1][j],nums[j] - dp[i][j - 1]);
                }
            }
        }
        if(dp[0][n - 1] >= 0) return true;
        return false; 
    }
};