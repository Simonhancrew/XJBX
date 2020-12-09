#include <vector>
#include <string>
//双序列型动态规划
//还是看最后一个字符，正则表达式最后一个字符p[n - 1]
//最后一个p是正常字符或者.就正常匹配
//如果是*的话，两种情况，串1已经被匹配完了，不用例会p的最后两个字符，或者串1的最后一个要和p最后一个匹配则必有s[m - 1] = p[n - 2]
//dp[i][j] 就是s的前i和p的前j能否匹配
using namespace std;
class Solution {
public:
    //需要注意边界的if判断
    bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        int dp[m + 1][n + 1];
        for(int i = 0;i <=m;++i){
            for(int j = 0;j <= n;++j){
                //初始情况
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                    continue;
                }
                //空串无法配出实串
                if(j == 0){
                    dp[i][j] = false;
                    continue;
                }
                //如果没用vector声明了数组的话记得此时赋值
                dp[i][j] = false;
                //最后一个不是*，考虑他们能不能匹配
                if(p[j - 1] != '*'){
                    //考虑i的边界
                    if(i > 0 && (p[j - 1] == '.' ||p[j - 1] == s[i - 1])){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }else{
                    //最后一个为*时
                    if(j >= 2){
                        //前面的串已经被匹配完了，最后的两个*x不要了
                        dp[i][j] |= dp[i][j - 2];
                    }
                    if(i >= 1 && j >= 2){
                        //s最后一个char没有被匹配，需要和统配匹配
                        dp[i][j] |= dp[i - 1][j] && (p[j - 2] == '.' ||s[i - 1] == p[j - 2]);
                    }

                }
            }
        }
        return dp[m][n];
    }
};