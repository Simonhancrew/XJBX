#include <vector>
using namespace std;
//最长序列型动态规划
//dp[i]，以i结尾时，最长的序列长度
//dp[i] = max(1,dp[j] + 1)其中j在0，i的范围内且nums[i] > nums[j]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        int Lis =1;
        for(int i=1;i<dp.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(Lis<dp[i]){
                Lis = dp[i];
            }
        }
        return Lis;
    }
};

//开数组记录长度为i的上升子序列的最小结束值，这个数组一定是递增的，可以证明
//然后二分的找到nums大于的值，这个值取到最大，然后更新数组b[i+1]
//贪心和2分查找的方法
#include <climits>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        //记录长度为i的上升子序列下最小的序列终值
        //这个序列一定是递增的，可以反证
        vector<int> dp(n + 1);
        //将dp[0] 设置为最小，不论如何最小长度都可以到达1
        dp[0] = INT_MIN;
        //记录当前最长
        int curLongest = 0;
        //顺序遍历数组
        for(int i = 0;i <=n;++i){
            int start = 0,stop = curLongest;
            int mid;
            int j = 0;
            //二分的查找序列中的最后一个比nums[i]小的值
            while(start <= stop){
                mid = (start + stop) / 2;
                if(dp[mid] < nums[i]){
                    j = mid;
                    start = mid + 1;
                }
                else{
                    stop = mid - 1;
                }
            }
            //找到当前的插入点，长度+1
            dp[j + 1] = nums[i];
            //更新长度
            if(j + 1 > curLongest){
                curLongest = j + 1;
            }
        }
        return curLongest;
    }
};