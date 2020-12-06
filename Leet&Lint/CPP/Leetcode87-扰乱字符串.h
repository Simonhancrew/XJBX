#include <vector>
#include <string>
using namespace std;
//s1和s2的长度不一致肯定不能变
//长度一致，可以变，我们知道最初是怎么二分的
//t = t1 + t2 s = s1 + s2;
//s1 -> t1 || s1 ->t2
//dp[i][j][k] -> 从s1的i位置，s2的j位置开始，长度为k的子串，是否能相互变
//dp[i][j][k] = dp[i][j][w] && dp[i + w][j + w][k - w] or (dp[i][j+k-w][w] && dp[i+w][j][k-w])
//其中w属于[1，k-1]
class Solution {
public:
    bool isScramble(string s1, string s2) {
        //长度不等，一定不能变
        if(s1.size() != s2.size()){
            return false;
        }
        const int n = s1.size();
        //初始一下区间dp数组，最后因为是长度，所以初始称n+1
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n+1,0)));
        //长度为1的时候判断
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        //长度是更长的时候
        for(int k = 2;k <= n;++k){
            for(int i = 0;i <= n - k;++i){
                for(int j = 0;j <= n-k;++j){
                    //开始不知道怎么分，找这个分的长度
                    for(int w = 1;w <= k - 1;++w){
                        //如果有一种分割可以完成
                        //映射关系是s1 -> t1
                        if(dp[i][j][w] && dp[i + w][j + w][k - w]){
                            dp[i][j][k] = 1;
                            break;
                        }
                        //映射关系是s1 ->t2
                        if(dp[i][j + k -w][w] && dp[i + w][j][k - w]){
                            dp[i][j][k] = 1;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};