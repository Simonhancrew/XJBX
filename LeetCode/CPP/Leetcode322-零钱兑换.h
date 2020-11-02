#include <vector>
using namespace std;
//动态规划：求最值和可能性问题
//考虑子问题最优化，先考虑最后一步，假设已经完成了，然后分解成了下一个子问题
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        //开dp数组，-1无法拼成
        for (int i = 0;i<=amount;i++){
            dp.push_back(-1);
        }
        dp[0] =0;//init初始状态
        for(int i=1;i<=amount;i++){
            //遍历可能的币制
            for(int j=0;j<coins.size();j++){
                //如果币制比当前i值大就没必要执行可能性更新了
                //如果dp[i] < dp[i - coins[j]] + 1也无需更新，已经存在的解是更优
                if(i-coins[j]>=0&&dp[i-coins[j]]!=-1){
                    if(dp[i]==-1||dp[i]>dp[i-coins[j]]+1){
                        dp[i] = dp[i-coins[j]]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};