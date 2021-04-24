#include <iostream>
#include <cstring>
#include <algorithm>

//状态压缩，第一维放的是走过路径的二进制的标识
//考虑最后一步，走到了j位置，他之前可以走那些位置呢？，这些位置的集合中选择k，从0 - k走到的最短汉密尔顿路径,再加上从k到j的hamilton路径。
//dp[i][j] = min(dp[i][j],dp[i - 1 << j][k] + w[k][j])
//只要走过的路径i中包含j，且包含k就可以转移过来
using namespace std;

const int N = 21,M = 1 << N;

int w[N][N];
int dp[M][N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> w[i][j];
        }
    }
    
    memset(dp,0x3f,sizeof dp);
    dp[1][0] = 0;
    
    for(int i = 0;i < 1 << n;i++){
        for(int j = 0;j < n;j++){
            if(i >> j & 1){//路径要包含j才能转移
                for(int k = 0;k < n;k++){
                    if(i - (1 << j) >> k & 1){//要包含k才能转移
                        dp[i][j] = min(dp[i][j],dp[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}