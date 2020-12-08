//双序列型动态规划
#include <vector>
#include <string>
using namespace std;
//最后一步，s3的最后一个字符是从那里来的？
//往之前推导，s3的前k个字符是否由s1的前i个，s2的前k个组成
//dp[i][j] = dp[i - 1][j] && (s1 == s3) or dp[i][j - 1] && s2 == s3
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(),n = s2.size(),t = s3.size();
        //无法组成
        if(m + n != t){
            return false;
        }
        vector<vector<int>> dp(m + 1,vector<int> (n + 1,false));
        //序列型，找初始条件
        dp[0][0] = true;
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                int pos = i + j - 1;
                //边界条件
                if(i > 0 && s1[i - 1] == s3[pos]){
                    dp[i][j] |= dp[i - 1][j];
                }
                if(j > 0 && s2[j - 1] == s3[pos]){
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }

    //滚动数组优化空间复杂度
    bool isInterleaveRollarry(string s1, string s2, string s3){
        auto f = vector <int> (s2.size() + 1, false);
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t) {
            return false;
        }
        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};
