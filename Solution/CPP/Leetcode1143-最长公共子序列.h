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
//双序列型动态规划，开dp的意思就是前i个字符
//最后一步，去掉尾，看尾部在不再最长序列中
//不同于区间型，之后之前的有关，所以不需要长度作为状态量
//dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1] + 1|A[i] = A[j])
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int m = text1.size(),n = text2.size();
        //初始条件空串和任何串都是0
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i =1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

//如何找到这个子序列呢？
//需要记录每一个dp[i][j]所作的决策，所以需要多开一个pai数组
//dp的转移方程中，只有三种情况，所以记录这三种就可以
#include <iostream>
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int m = text1.size(),n = text2.size();
        //初始条件空串和任何串都是0
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        vector<vector<int>> pai(m + 1,vector<int> (n + 1,0)); 
        for(int i =1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j] == dp[i-1][j]){
                    pai[i][j] = 1;
                }else{
                    pai[i][j] = 2;
                }
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
                    if(dp[i][j] == dp[i - 1][j - 1] + 1){
                        pai[i][j] = 3;
                    }
                }
            }
        }
        string res(dp[m][n],'0');
        int pos = dp[m][n] - 1;
        int i = m,j = n;
        while(i > 0 && j > 0){
            if(pai[i][j] == 1){
                --i;
            }else if(pai[i][j] == 2){
                --j;
            }else{
                res[pos--] = text1[i - 1];
                --i;
                --j;
            }
        }
        cout << res;
        return dp[m][n];
    }
}; 