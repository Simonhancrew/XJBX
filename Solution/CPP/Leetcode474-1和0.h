#include <vector>
#include <string>
using namespace std;
//一个序列动态规划
//看最后一个放不放入
//不放入就情况1，放入就是情况2
//dp[i][j] = max(dp[i-1][j][k],dp[i-1][j-cnt0][k-cnt1] +1)
//此时需要知道还有多少01
//0和1数量进状态，开三位数组
//之后可以用old和now改成2维数组
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int T = strs.size();
        vector<int> cnt0(T,0),cnt1(T,0);
        //统计一下每个字符里的01数量
        for(int i = 0;i < T;++i){
            for(int j = 0;j < strs[i].size();++j){
                if(strs[i][j] == '0'){
                    cnt0[i]++;
                }else{
                    cnt1[i]++;
                }
            }
        }
        int dp[T + 1][m + 1][n + 1];
        //初始，空数组无法被匹配
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                dp[0][i][j] = 0;
            }
        }
        //数组序
        for(int i = 1;i <= T;++i){
            //dp中的剩下的0
            for(int j = 0;j <= m;++j){
                //dp中剩下的1
                for(int k = 0;k <= n;++k){
                    //初始，不组下一个字符串
                    dp[i][j][k] = dp[i-1][j][k];
                    //如果足够组下一个字符串
                    if(j >= cnt0[i - 1] && k >= cnt1[i - 1]){
                        //in
                        dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - cnt0[i - 1]][k - cnt1[i - 1]] + 1);
                    }
                }
            }
        }
        return dp[T][m][n];
    }
};

//改滚动数组
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int T = strs.size();
        vector<int> cnt0(T,0),cnt1(T,0);
        //统计一下每个字符里的01数量
        for(int i = 0;i < T;++i){
            for(int j = 0;j < strs[i].size();++j){
                if(strs[i][j] == '0'){
                    cnt0[i]++;
                }else{
                    cnt1[i]++;
                }
            }
        }
        //c99标准是可以变量声明的，一定注意赋值！！！！！
        //c++中三维变量也可以变量声明，但第一个必须是常数，也要注意赋值
        int dp[2][m + 1][n + 1];
        int now = 0,old = 0;
        //初始，空数组无法被匹配
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                dp[now][i][j] = 0;
            }
        }
        //数组序
        for(int i = 1;i <= T;++i){
            old = now;
            now = 1- now;
            //dp中的剩下的0
            for(int j = 0;j <= m;++j){
                //dp中剩下的1
                for(int k = 0;k <= n;++k){
                    //初始，不组下一个字符串
                    dp[now][j][k] = dp[old][j][k];
                    //如果足够组下一个字符串
                    if(j >= cnt0[i - 1] && k >= cnt1[i - 1]){
                        //in
                        dp[now][j][k] = max(dp[now][j][k],dp[old][j - cnt0[i - 1]][k - cnt1[i - 1]] + 1);
                    }
                }
            }
        }
        return dp[now][m][n];
    }
};


//借鉴一维背包的空间优化，逆序。
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        int dp[n + 1][m + 1];
        memset(dp,0,sizeof dp);
        for(int i = 1;i <= length;i++){
            int cm = 0,cn = 0;  //0,1个数
            for(auto &ch:strs[i - 1]){
                if(ch == '0') cm++;
                else cn++;
            }
            for(int j = n;j >= cn;j--){
                for(int k = m;k >= cm;k--){
                    dp[j][k] = max(dp[j][k],dp[j - cn][k - cm] + 1);
                }
            }
        }
        return dp[n][m];
    }
};