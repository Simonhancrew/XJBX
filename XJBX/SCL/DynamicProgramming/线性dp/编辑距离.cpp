#include <iostream>
#include <cstring>
#include <algorithm>

//就是编辑距离的简单应用

using namespace std;

const int N = 20,M = 1e3 + 10;

int dp[N][N];
char str[M][N];

int edit_dis(char a[],char b[]){
    int la = strlen(a + 1),lb = strlen(b + 1);
    
    for(int i = 0;i <= la;i++) dp[i][0] = i;
    for(int i = 0;i <= lb;i++) dp[0][i] = i;
    
    for(int i = 1;i <= la;i++){
        for(int j = 1;j <= lb;j++){
            dp[i][j] = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + 1);
        }
    }
    return dp[la][lb];
}

int main()
{
    int m,n;
    cin >> n >> m;
    for(int i = 0;i < n;i++) scanf("%s",str[i] + 1);
    
    while(m--){
        char s[N];
        int limit;
        scanf("%s%d",s + 1,&limit);
        int res = 0;
        for(int i = 0;i < n;i++){
            if(edit_dis(str[i],s) <= limit){
                res ++;
            }
        }
        cout << res << endl;
        
    }
    return 0;
}