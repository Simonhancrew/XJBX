#include <iostream>
#include <algorithm>

using namespace std;

//动态规划还是需要经验，很多直接想出来其实不太可能
//以分界线作为最后的分堆标准，左边和为一堆，右边另一堆
//快速处理部分和需要用到前缀和
//这里从前往后枚举是不对的，需要枚举区间长度（可能多次枚举一个区间长度）
//或者你逆序枚举，要保证用到的状态之前已经算过了

const int N = 310;
int dp[N][N];
int s[N];

int main(){
    int n;
    cin >> n;
    //算一下前缀和
    for(int i = 1;i <= n;i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    //按照长度从小到大枚举所有的状态
    //长度为1的时候合并没有代价，不考虑
    for(int len = 2;len <= n;len++){
        for(int i = 1;i + len - 1 <= n;i++){
            //区间做右端点
            int l = i,r = i + len - 1;
            //记得初始代价为无穷大，负责dp为0，代价已经最小了
            dp[l][r] = 1e9;
            //枚举可以的划分区间
            for(int k = l;k < r;k++){
                dp[l][r] = min(dp[l][r],dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}