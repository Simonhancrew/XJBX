#include <iostream>
#include <algorithm>

//多重背包问题，同一个重量和value的物品有n件
//所以朴素的解法和多重背包是很类似的，但是无法用本层的去优化，因为是限制了同一个物品可以拿的数量，所以本层的
//dp[i][j - v] = max(             dp[i - 1][j - v], dp[i - 1][j - 2 * v] + w, dp[i - 1][j - 3 * v] + 2 * w, ...dp[i-1][j - sv - v] + s * w)
//不能直接来优化,范围扩大的话，会超时.
//这里引入二进制优化的方式,我们考虑打包的方式来优化，一个物品可以打包成1，2，4。。。。。2**k个包，这些包一定能够拼凑出完整的k个物品的价值，
//之后对这些包做一次01背包问题就可以了

using namespace std;

const int N = 23000,M = 2e3 + 10;
int v[N],w[N];
int dp[M];

int main()
{
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            k *= 2;
            s -= k;
        }
        if(s > 0){
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }

    }
    //此时物品被打包，等价于只有cnt个物品
    n = cnt;
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= v[i];j--){
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}