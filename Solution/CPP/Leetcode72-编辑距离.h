#include <string>
using namespace std;
//暴力或者动态规划
/*
    动态规划
    dp[i][j] = str1到i位置，str2到j位置，两者之间的编辑距离
    实质上的编辑距离可以从子状态推导而来，是dp[i-1][j],dp[i][j-1],dp[i-1][j-1]里的最小者加一
    分别对应着a插入一个字符，b插入一个字符，a替换一个字符
*/
class Solution {
public:
    int minDistance(const string &word1,const string &word2){
        int n = word1.size();
        int m = word2.size();
        //有一个串为0的话直接返回编辑距离
        if(m*n == 0){
            return m+n;
        }
        //拿到所有的dp，代表0-i位置和0-j位置的两个串之间的编辑距离
        int dp[n+1][m+1];
        //初始条件，空串
        for(int i = 0;i<n+1;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j<m+1;j++){
            dp[0][j] = j;
        }
        //依次得到d[i][j]
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                int left = dp[i-1][j]+1;
                int up = dp[i][j-1]+1;
                int left_up = dp[i-1][j-1];
                //从1开始的串下标的数组之间下标的映射是少1的
                if(word1[i-1] != word2[j-1]){
                  left_up++;
                }
                dp[i][j] = min(up,min(left,left_up));
            }
        }
        return dp[n][m];
    }
};

//双序列型动态规划
//考虑最后一步，，假设前面的子问题已经最优了，长度最后会变成一样，最后一个数要相等s1[n - 1] == s2[n - 1];
//什么都不做,插入字符，删除字符，替换字符。s1的前n - 1,s2的前n - 1
//dp[i][j]--s1的前i个字符和s2的前j个字符的编辑距离
//dp[i][j] = min(dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1,dp[i - 1][j] + 1,dp[i - 1][j - 1]|s1[i -1] = s2[j -1])
//s1增加一个字符，s1和s2替换一个字符，s1删掉一个字符，s1和s2最后一个字符相等
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int m = word1.size(),n = word2.size();
        if(m * n == 0){
            return m + n;
        }
        int dp[m + 1][n + 1];
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                if(j == 0){
                    dp[i][0] = i;
                    continue;
                }
                if(i == 0){
                    dp[0][j] = j;
                    continue;
                }
                //s1增加一个数，s1删除一个数
                dp[i][j] = min(dp[i][j-1] + 1,dp[i - 1][j] + 1);
                //s1和s2长度相等，最后一个不等，替换一个
                dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + 1);
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

//改滚动数组,2*n
//他只和之前一行的数据相关
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int m = word1.size(),n = word2.size();
        if(m * n == 0){
            return m + n;
        }
        int dp[2][n + 1];
        int old = 0, now = 0;
        for(int i = 0;i <= m;++i){
            old = now;
            now = 1- now;
            for(int j = 0;j <= n;++j){
                if(j == 0){
                    dp[now][j] = i;
                    continue;
                }
                if(i == 0){
                    dp[now][j] = j;
                    continue;
                }
                //s1增加一个数，s1删除一个数
                dp[now][j] = min(dp[now][j-1] + 1,dp[old][j] + 1);
                //s1和s2长度相等，最后一个不等，替换一个
                dp[now][j] = min(dp[now][j],dp[old][j - 1] + 1);
                if(word1[i - 1] == word2[j - 1]){
                    dp[now][j] = min(dp[now][j],dp[old][j - 1]);
                }
            }
        }
        return dp[now][n];
    }
};