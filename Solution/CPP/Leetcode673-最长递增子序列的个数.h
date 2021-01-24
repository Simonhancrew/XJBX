#include <vector>
using namespace std; 
//维护两个序列
//并且要记录最长的长度
//让再次遍历的时候把该长度的count加起来
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        //i之前，最长的递增序列的长度
        vector<int> dp(n,1);
        //i此时的最长长度有多少个
        vector<int> count(n,1);
        //记录最长的长度是多少
        int maxcount = 0;
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    //只有两种情况更新dp
                    //一种找到了更长的，一种找到了相等的
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    } 
                }
                if(dp[i] > maxcount) maxcount = dp[i];
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            if(maxcount == dp[i]){
                res += count[i];
            }
        }
        return res;
    }
};