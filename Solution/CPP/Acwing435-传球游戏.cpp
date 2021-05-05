#include <iostream>

using namespace std;
const int N = 35;

int m,n;
int dp[N][N];

int main()
{
    cin >> n >> m;
    dp[0][1] = 1;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(j == 1){
                dp[i][j] = dp[i - 1][2] + dp[i - 1][n];   
            }else if(j == n){
                dp[i][j] = dp[i - 1][1] + dp[i - 1][j - 1];
            }else{
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    cout << dp[m][1] << endl;
    return 0;
}
