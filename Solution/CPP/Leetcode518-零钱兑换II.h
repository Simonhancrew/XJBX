#include <vector>
using namespace std;
//完全背包问题，顺序有要求
//找递推，首先amount为0，不用金币也可以拼出dp[0]
//用2的金币，则偶数的都可以拼出来
//用5的金币，5的倍数的都可以拼出来
//以此类推
//这之间是一个加的关系 +=
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = coins[i];j <= amount;j++){
                dp[j] += dp[j - coins[i]];//装满背包的方法 +=
            }
        }
        return dp[amount];
    }
};