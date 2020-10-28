#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    //开备忘录的原因是为了去除重叠子问题
    vector<vector<int>> memo;
    int longestCommonSubsequence(string &text1, string &text2) {
        int t1 = text1.size(),t2 = text2.size();
        //二维数组的resize
        vector<int> temp(t2,-1);
        memo.resize(t1,temp);
        return dp(text1,0,text2,0);
    }
private: 
    int dp(string &text1,int i, string &text2, int j){
        //1 达到终点
        if(i == text1.size() || j == text2.size()){
            return 0;
        }
        //如果之前出现在记忆数组中过
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        //如果当前二者相等，肯定在结果中
        if(text1[i] == text2[j]){
            memo[i][j] = 1+dp(text1,i+1,text2,j+1);
        }else{
            //当前不等，两者之一前进一个，去最大值
            memo[i][j] = max(dp(text1, i + 1, text2, j), dp(text1, i, text2, j + 1));
        }
        return memo[i][j];
    }
};


//自底向上
class Solution {
public:
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