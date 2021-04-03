#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

//海水堪称一个虚拟节点，链接着矩阵外围的边，找到出海的权值的最大路的最小值
//格子里的水从这个最小的山峰流往大海
//找到最短路中权边的最大值

using namespace std;


const int N = 55;

int n,m;
int h[N][N],dist[N][N];
bool st[N][N];

struct Node{
    int x,y,d;
    bool operator <(const Node& t) const{
        return d > t.d;
    }
};

int main(){
    int t;
    cin >> t;
    for(int c = 1;c <= t;c++){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                cin >> h[i][j];
            }
        }
        memset(dist,0x3f,sizeof dist);
        memset(st,0,sizeof st);
        priority_queue<Node> heap;
        for(int i = 1;i <= n;i++){
            heap.push({i,1,h[i][1]});
            dist[i][1] = h[i][1];
            heap.push({i,m,h[i][m]});
            dist[i][m] = h[i][m];
        }

        for(int i = 2;i < m;i++){
            heap.push({1,i,h[1][i]});
            dist[1][i] = h[1][i];
            heap.push({n,i,h[n][i]});
            dist[n][i] = h[n][i];
        }
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        int res = 0;
        while(heap.size()){
            auto t = heap.top();
            heap.pop();
            if(st[t.x][t.y]) continue;
            st[t.x][t.y] = true;
            res += t.d - h[t.x][t.y];
            for(int i = 0;i < 4;i++){
                int x = t.x + dx[i],y = t.y + dy[i];
                if(x >= 1 && x < n && y >= 1 && y <= m){
                    if(dist[x][y] > max( t.d,h[x][y])){
                        dist[x][y] = max(t.d,h[x][y]);
                        heap.push({x,y,dist[x][y]});
                    }
                }
            }
        }
        printf("Case #%d: %d\n",c,res);
    }  
    return 0;
}