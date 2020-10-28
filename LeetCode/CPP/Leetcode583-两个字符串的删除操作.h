#include <string>
#include <vector>
using namespace std;
//删除的结果就是最长公共子序列，可以从以上地推过来
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        int m = word1.size(),n =word2.size();
        return m+n-2*lcs; 
    }
private:
    int longestCommonSubsequence(string &text1, string &text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i =1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};