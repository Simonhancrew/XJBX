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