#include <iostream>
#include <algorithm>

//多重背包问题，同一个重量和value的物品有n件
//所以朴素的解法和多重背包是很类似的

using namespace std;

const int N = 110;
int v[N],w[N],s[N];
int dp[N][N];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i] >> s[i];
    
    for(int i = 1;i <= n;i++){
        for (int j = 0; j <= m; j ++ ){
            for(int k = 0;k <= s[i] && k * v[i] <= j;k++){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - k * v[i]] + k * w[i]);
            } 
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}