#include <iostream>
#include <cstring>
#include <algorithm>
//朴素的做法，考虑最后一步，拿与不拿，这个时候完全背包不同于01，它可以无限次拿去一个物品
//只要空间还是存在的，所以我们朴素的做法就是枚举三个维度，前i个元素，背包重量，和拿k个第i个物品
using namespace std;

const int N = 1e3 + 10;
int v[N],w[N];
int dp[N][N];

int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0;k * v[i] <= j;k++){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

//之后我们考虑优化这个三维的循环，
//考虑到dp[i][j]= max(dp[i - 1][j], dp[i - 1][j - v] + w, dp[i - 1][j - 2 * v] + 2 * w, dp[i - 1][j - 3 * v] + 3 * w);
// dp[i][j - v] = max(             dp[i - 1][j - v], dp[i - 1][j - 2 * v] + w, dp[i - 1][j - 3 * v] + 2 * w, .....)；
//dp[i][j - v]和dp[i][j]的转移公式后半部分就少了一个w，好像有重复计算的部分可以拿出来用，此时我们可以简化第三个循环
//dp[i][j] = max(dp[i-1][j],dp[i][j - v] + w),可以用本层的元素去做优化

int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]){
                dp[i][j] = max(dp[i][j],dp[i][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

//同理我们再去考虑滚动数组
int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
    int old = 0,now = 0;
    for(int i = 1;i <= n;i++){
        old = now;
        now = 1 - now;
        for(int j = 0;j <= m;j++){
            dp[now][j] = dp[old][j];
            if(j >= v[i]){
                dp[now][j] = max(dp[now][j],dp[now][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[now][m] << endl;
    return 0;
}

//最后可以考虑一维的优化，此处不同于01背包，用到的状态都是本层的，不需要去逆序推
//直接本层的改就可以了
int f[N];
int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(j >= v[i]){//此处可以继续优化，j从v[i]开始枚举
                f[j] = max(f[j],f[j - v[i]] + w[i]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}