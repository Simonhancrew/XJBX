#include <vector>
//本题和分割等和子集的方法高度类似
//还是一个01背包问题
//dp[i]，承重i的背包中，最多可以放的价值
//为什么不用多维dp？
//仔细看就会发现dp的值是可以复用的，参考背包九讲
//需要注意的是为了在遍历中为了不重复的放入，需要考虑是按照背包的重量逆序的
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int res = 0;
        for (auto stone:stones){
            res += stone;
        }
        //就是分成重量差不多的两堆，看这两堆碰撞之后剩下多少
        int n = stones.size();
        int target = res / 2; 
        //可称重为n的背包中，能装的最大重量
        vector<int> dp(target+1);
        //要不要初始化？不用，因为背包称重永远大于当前遍历的石头的重量
        for(int i = 0;i < n;i++){
            //为什么要反向遍历？
            //从后往前，防止多次放入同一个石头
            for(int j = target;j >= stones[i];--j){
                dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);
            }
        }
        return res - dp[target] - dp[target];
    }
};