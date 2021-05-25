#include <vector>
#include <algorithm>
#include <unordered_map>

// 1 根据k距离的异或和为0不难推得nums[i] == nums[i + k]
// 2 将这个数组看成列为k的矩形，每一行的异或和为0,每一列的元素是要相等的,cnt是一列的元素总数
// 3 dp[i][j]前i组，每行的异或和为j需要的改变次数
// 4 枚举第二维的x，在i列中，x存在的话，dp[i][j] = dp[i - 1][j ^ x] + cnt - countx,countx是一列中x的数量(这里可以用哈希记录) 
// 5 在第i列中，x不存在的话就是min(dp[i - 1][j]) + cnt,一列全部要替换，此时只要去前一列的最小值就行了（求最小，无关项添加为所谓）

using namespace std;

class Solution {
public:
    static constexpr int N = 1 << 10;
    int minChanges(vector<int>& nums, int k) {
        int dp[k][N];
        int g[k];//上一列的最小，用来加速
        int n = nums.size();
        memset(dp,0x3f,sizeof dp);
        memset(g,0x3f,sizeof g);//每一列的最小值
        for(int i = 0;i < k;i++){
            unordered_map<int,int> hash;
            int cnt = 0;
            //这一列的总元素和hash表的构建
            for(int j = i;j < n;j+=k){
                cnt++;
                hash[nums[j]]++;
            }
            //第一列的时候只要知道改变的个数就可以了
            if(i == 0){
                for(int mask = 0;mask < N;mask++){
                    int add = 0;
                    if(hash.count(mask)) add = hash[mask];
                    dp[0][mask] = min(dp[0][mask],cnt - add);
                    g[0] = min(g[0],dp[0][mask]);
                }
            }else{//其余列要求最小，要知道上一列的修改最小，然后状态转移
                for(int mask = 0;mask < N;mask++){
                    dp[i][mask] = g[i - 1] +cnt;
                    for(auto [x,countx]:hash){
                        dp[i][mask] = min(dp[i][mask],dp[i - 1][mask ^ x] + cnt - countx);
                    }
                    g[i] = min(g[i],dp[i][mask]);
                }
            }
        }
        return dp[k - 1][0];
    }
};