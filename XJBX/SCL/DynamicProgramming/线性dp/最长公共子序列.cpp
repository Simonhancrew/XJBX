#include <iostream>
#include <cstring>
#include <algorithm>

//dp[i][j]，s1的前i和s2的前j的最长公共子序列是多少

using namespace std;

const int N = 1e3 + 10;
int dp[N][N];
char a[N],b[N];

int main()
{
    int m,n;
    cin >> m >> n;
    scanf("%s%s",a + 1,b + 1);
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}