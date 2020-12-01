#include <vector>
#include <algorithm>
using std::min;
using std::max;
using std::vector;
//开动态规划的数组
//从1开始枚举，直到T，这样就能递推的得到每一个需要的区间的解
//如果在clips数组中，i在某个区间中，则需要更新dp[i],他的值就是dp[i] 和dp [clip[0]] + 1 中的较小者 
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1,INT_MAX - 1);
        //覆盖0所需要的长度0
        dp[0] = 0;
        //枚举i
        for(int i = 1;i <= T;i++){
            for(auto clip:clips){
                if(clip[0] < i && clip[1] > i){
                    dp[i] = min(dp[i],dp[clip[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1? -1:dp[T];
    }
};

//贪心
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int last = 0, ret = 0, pre = 0;
        for (vector<int>& it : clips) {
            if (it[0] < T) {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++) {
            last = max(last, maxn[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
