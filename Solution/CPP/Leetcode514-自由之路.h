#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//dp[i][j] key的i位置对其ring的j位置需要的步数最少
class Solution {
public:
    int findRotateSteps(string &ring, string &key) {
        int n = ring.size();
        int m = key.size();
        //建立一个ring出现的单词到位置的映射
        vector<int> pos[26];
        for(int i = 0;i < n;++i){
            pos[ring[i] - 'a'].push_back(i);
        }
        //转移矩阵
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        //对于key首位置，每一个可以对齐的ring位置转移矩阵值(顺时针逆时针)
        for(auto &i:pos[key[0] - 'a']){
            dp[0][i] = min(i,n-i) + 1;
        }
        for(int i = 1;i < m;++i){
            //找打能在ring上对其的所有的位置
            for(auto &j:pos[key[i] - 'a']){
                //跟前一步相关
                for(auto &k:pos[key[i - 1] - 'a']){
                    //关系到之前一个key[i-1]的对齐的转移，顺时针+逆时针
                    dp[i][j] = min(dp[i][j],dp[i-1][k] + min(abs(j-k),n - abs(j-k)) + 1);
                }
            }
        }
        //因为对齐是找到所有的可以对其的都对一遍，只要找到m-1位置上的最小值就可以了
        return *min_element(dp[m-1].begin(),dp[m-1].begin() + n);
    }
};