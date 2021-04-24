#include <iostream>
#include <cstring>
#include <algorithm>

//这一题不太好用dp，状态开始可以有多个，转移是可以从四个方向来的
//记忆化搜索就很舒服，枚举每个开始的位置

using namespace std;

const int N = 310;
int g[N][N];
int f[N][N];
int n,m;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x,int y){
    int &v = f[x][y];
    if(v != -1) return v;
    
    v = 1;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx <= n && nx >= 1 && ny >= 1 && ny <= m && g[nx][ny] < g[x][y]){
                v = max(v,dp(nx,ny) + 1);
            }
        }
    }
    return v;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> g[i][j];
        }
    }

    //记忆化搜索一般初始一个值当有没有搜索过的判据
    memset(f,-1,sizeof f);
    int res = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            //此时的f[i][j]是没有搜索过的
            res = max(res,dp(i,j));
        }
    }
    cout << res << endl;
    return 0;
}