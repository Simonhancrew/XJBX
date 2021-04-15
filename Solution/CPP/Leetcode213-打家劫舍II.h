#include <vector>
using namespace std;
//对于圈的处理，就去处理首尾，找到不同的情况，去头去尾
//不同时处理，就变成序列了
class Solution {
public:
    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        //case1 去头求res
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2;i < n;++i){
            //注意要加的nums的index
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        int res1 = dp[n-1];
        //case2 去尾求res
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2;i < n;++i){
            //注意index
            dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
        }
        res1 = max(res1,dp[n-1]);
        return res1;
    }
};

class Solution{
public:
    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if (n == 1){
            return nums[0];
        }
        int res1 = rangeRob(nums,0,n - 2);
        int res2 = rangeRob(nums,1,n - 1);
        return max(res1,res2);
    }

    int rangeRob(vector<int> &nums,int start,int end){
        if(end == start){
            return nums[start];
        }
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start],nums[start + 1]);
        for(int i = start + 2;i <= end;i++){
            dp[i] = max(dp[i - 2] + nums[i],dp[i-1]);
        }
        return dp[end];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        //偷第一个
        int old = 0;
        int now = nums[0];
        for(int i = 2;i < n;i++){
            int t = now;
            now = max(now,old + nums[i-1]);
            old = t;
        }
        int res = now;
        old = 0,now = nums[1];
        for(int i = 2;i < n;i++){
            int t = now;
            //序列dp注意idx，这里其实往前推进了一位
            now = max(now,old + nums[i]);
            old = t;
        }
        return max(now,res);
    }
};