#include <string>
#include <vector>
using namespace std;
//划分型动态规划
//动态规划，最优最后一步，最后一段，假设最后分割的一个串回文，结果就是dp[j-1] + 1;
class Solution {
public:
    int minCut(string s) {
        if(s.size() == 0){
            return 0;
        }
        int n = s.size();
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        //确定一下回文串,针对每一个值，以他为奇或偶回文中心，往两边扩大
        for(int t = 0;t < n;++t){
            //奇数长度的回文串
            int i = t,j = t;
            while(i >= 0 && j < n && s[i] == s[j]){
                isPalindrome[i][j] = true;
                --i;
                ++j;
            }
            //偶数长度的回文串
            i = t, j = t + 1;
            while(i >= 0 && j < n && s[i] == s[j]){
                isPalindrome[i][j] = true;
                --i,++j;
            }   
        }
        //序列型动态规划，前i位置的最优划分多少
        vector<int> dp(n + 1,INT_MAX);
        dp[0] = 0;
        //dp[i] = min(dp[j] + 1,dp[i]), 0 =< j < i 
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < i;++j){
                if(isPalindrome[j][i - 1]){
                    dp[i] = min(dp[j] + 1,dp[i]);
                }
            }
        }
        //返回的时划分的次数
        return dp[n] - 1;
    }
};