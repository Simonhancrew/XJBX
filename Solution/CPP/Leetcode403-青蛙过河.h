#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//坐标+状态
//最后一步，假设能跳道终点，跳的长度为L，前面子问题最优化
//之前的一步从stones[i] = stones[n - 1] - L跳过来的
//考虑能否跳到stones[i]
//倒数第二跳只能是L 和 L +-1
//dp[i][j]表示这一条能否跳长度j到达i
//可以用一个哈希表来加速，上一块石头是stones[k]  = stones[i] - j,stones[k] -> k
//dp[i][j] = dp[k][j - 1] or dp[k][j] or dp[k][j + 1] | stones[k] = stones[i] - j 
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        //mp[stones[i]]是一个set,x在这个集合中
        //dp[i][x]，dp[i][x] = true;
        //x是一个长度
        unordered_map<int,unordered_set<int>> dp;
        //init
        for(int i = 0;i < n;++i){
            dp.insert({stones[i],unordered_set<int>()}); 
        }
        dp[stones[0]].insert(0);
        //每个石头贡献值，看能不能跳到最后的一块上
        for(int i = 0;i < n - 1;++i){
            unordered_set<int> tmp = dp[stones[i]];
            for(auto k:tmp){
                for(int diff = -1;diff <= 1;++diff){
                    int t = stones[i] + (k + diff);
                    //找到能跳到的石头
                    if(dp.find(t) != dp.end()){
                        //更新里面能跳的长度
                        dp[t].insert(k + diff);
                    }
                }
            }
        }
        return !dp[stones[n - 1]].empty();
    }
};