#include <vector>
#include <algorithm>
using namespace std;

//转化成最长公共子序列问题

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        int dp[510][510];//数据范围500以内
        memset(dp,0,sizeof dp);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                if(nums1[i - 1] == nums2[j -1]) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
            }
        }
        return dp[n][m];
    }
};