#include <vector>
#include <string>
using namespace std;
//双序列型动态规划，和正则不同，如果最后是*的话,且*要发挥作用，dp是dp[i-1][j]
//*看作任意长的字符
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        int dp[m + 1][n + 1];
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                    continue;
                }
                if(j == 0){
                    dp[i][j] = false;
                    continue;
                }
                //注意dp[i][j]此时的值可能是未定义的
                dp[i][j] = false;
                if(p[j - 1] != '*'){
                    if(i > 0 && (p[j - 1] == '?' || p[j - 1] == s[i - 1])){
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }else{
                    //不关注*，之前就匹配完了
                    dp[i][j] |= dp[i][j-1];
                    //i = 0,j = 10可以进来
                    if(i > 0){
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

/*
双序列型动态规划的突破口
1 串A和B最后一个字符是否匹配
2 是否需要串A/B的最后一个字符
3 缩减规模，前面子问题最优
4 序列型，开的空间是要+1的，否则非常难处理空串
5 continue的注意
6 如果没用vector，需要注意dp[i][j]初始化
7 pai数组，记录每一步干嘛
8 匹配的时候不要忘了情况或者+1
*/