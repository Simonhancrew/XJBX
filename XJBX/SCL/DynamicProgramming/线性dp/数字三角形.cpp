#include <iostream>
#include <cstring>
#include <algorithm>

//线性dp比较简单，直接顺着线推就完了
//但是需要注意一下边界情况和初始化的问题（看清数据有没有负数）

using namespace std;

const int N = 510,INF = 1e9;
int t[N][N];
int dp[N][N];

int main(){
    int n;
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin >> t[i][j];
        }
    }
    //memset(dp,-0x3f,sizeof dp);
    //因为有负数，且每一行末尾的元素会看他的右上角，每一行的第一个元素会看他的左上角
    //所以需要初始化一些元素为负无穷（开始初始化0会影响负数的判定，比如负数在末尾的时候），且需要多初始化一维
    //第二行开始受影响，所以从0开始，到i+1结束
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i + 1;j++){
            dp[i][j] = -INF;
        }
    }
    
    dp[1][1] = t[1][1];
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= i;j++){
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1]) + t[i][j];
        }
    }
    int res = -INF;
    for(int i = 1;i <= n;i++) res = max(res,dp[n][i]);
    cout << res << endl;
    return 0;
}