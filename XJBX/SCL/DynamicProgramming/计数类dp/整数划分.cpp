#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//首先考虑完全背包的思路，前i个物品，拼凑出j的重量，dp是一共的方法数
//我们可以拿0 - s个i物品dp[i][j] = dp[i - 1][j] + dp[i- 1][j - i] .... + dp[i - 1][j - s * i]
//dp[i][j - i] = dp[i - 1][j - i] + dp[i - 1][j - 2i] +... + dp[i - 1][j - s*i];
//dp[i][j] = dp[i- 1][j] + dp[i][j - i]

const int N = 1e3 + 10,mod = 1e9 + 7;
int dp[N];

int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}