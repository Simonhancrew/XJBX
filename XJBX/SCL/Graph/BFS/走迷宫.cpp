#include <iostream>
#include <cstring>

// 要求权重必须是1

//BFS处理无权最段路的问题
//BFS按照层级数序遍历一个图，如果可能出现闭环的话需要标记搜索过的点位。
//基于这个性质可以按照层序去遍历到最短的距离

using namespace std;

typedef pair<int,int> PII;

const int N = 110;
int q[N][N],d[N][N];
PII que[N * N];
int m,n;

int bfs(){
    //模拟一个队列，要插入一个数，这里tt直接0了
    int hh = 0,tt = 0;
    que[0] = {0,0};
    //标记
    memset(d,-1,sizeof(d));
    d[0][0] = 0;
    //方向向量
    int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};
    while(hh <= tt){
        auto t = que[hh++];
        for(int i = 0;i < 4;i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && q[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                //入队列
                que[++tt] = {x,y};
            }
        }
    }
    return d[n - 1][m - 1];
}


int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int tmp;
            cin >> tmp;
            q[i][j] = tmp;
        }
    }
    
    cout << bfs() << endl;
    return 0;
}