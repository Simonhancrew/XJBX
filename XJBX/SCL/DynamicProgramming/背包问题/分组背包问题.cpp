#include <iostream>
#include <cstring>
#include <algorithm>

//还是考虑最后一步，拿不拿
//此时因为一组只能拿一个，所以需要新枚举一下每一组能拿的物品

using namespace std;

const int N = 110;

int v[N][N],w[N][N],s[N];
int dp[N];

int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
        for(int j = 0;j < s[i];j++){
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){//用的上一层的就逆序，用的本层的就顺序
            for(int k = 0;k <= s[i];k++){
                if(v[i][k] <= j){
                    dp[j] = max(dp[j],dp[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}

/*
一下是朴素的做法
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int v[N][N],w[N][N],s[N];
int dp[N][N];

int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
        for(int j = 1;j <= s[i];j++){
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0;k <= s[i];k++){
                if(v[i][k] <= j){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}
*/