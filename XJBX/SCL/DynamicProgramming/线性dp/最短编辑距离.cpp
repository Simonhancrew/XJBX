#include <iostream>
#include <algorithm>

//考虑最后一步，dp[i][j]a的前i变成b的前j
//最后一步可以增删改，我们求他的最小值
//首先增，在串1的后面+匹配串2，其次减，在串2的后面-匹配串1
//改要分情况考虑，最后一个相等就不需要改了，不等是需要改的
using namespace std;

const int N = 1e3 + 10;
char a[N],b[N];
int dp[N][N];

int main(){
    int n,m;
    scanf("%d%s",&n,a + 1);
    scanf("%d%s",&m,b + 1);

    //首先考虑边界初始,0变另外一个，直接删就可以了
    for(int i = 0;i <= m;i++) dp[0][i] = i;
    for(int i = 0;i <= n;i++) dp[i][0] = i;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            //之前状态最优，全部匹配，增和删。
            dp[i][j] = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}