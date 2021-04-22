//把N*M的棋盘，分割成若干个1*2的正方形，求方案数
//状态压缩dp里的状态虽然是整数，但你要把它看作二进制位
/*

1 横向的放完了，纵向的就只有一种情况放下去,所以只用枚举横向的格子是怎么放的
2 dp[i][j] ,i是按照列来枚举，j是二进制位，标识当前的格子状态，0标识无填充
3 首先不能和i-1的冲突 j & i-1的位状态 == 0，其次剩下的要用竖着的填，不能有奇数的0状态连续，否则无法填充完
4 状态压缩dp其实很简单

*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using LL = long long;

const int N = 12,M = 1 << N;
LL dp[N][M];
bool st[M];

int main(){
    int n,m;
    while(cin >> n >> m,m||n){
        for(int i = 0;i < 1 << n;i++){
            int cnt = 0;
            st[i] = true;
            for(int j = 0;j < n;j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }else{
                    cnt ++;
                }
            }
            if(cnt & 1) st[i] = false;
        }

        memset(dp,0,sizeof dp);
        //0列的时候前面没有伸过来的块，本身就是一种方案
        dp[0][0] = 1;

        for(int i = 1;i <= m;i++){
            //当前列的情况
            for(int j = 0;j < 1 << n;j++){
                //前一列伸过来的
                for(int k = 0;k < 1 << n;k++){
                    //此处可以用空间换事件，预处理无效的状态
                    if((j & k) == 0 && st[j | k]){//j和k的状态没有交际，前一列没有伸过来冲突的
                    //且两列都没有奇数连续的未放置空格（我们只考虑横向的安放，纵向的在横向的放好之后就只有一种方式放下）
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}


/*
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;
LL f[N][M];
vector<int> state[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i ++ )
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else cnt ++ ;
            if (cnt & 1) is_valid = false;
            st[i] = is_valid;
        }

        for (int i = 0; i < 1 << n; i ++ )
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j ++ )
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}

*/