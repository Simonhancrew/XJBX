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
        //初始化能初始的
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