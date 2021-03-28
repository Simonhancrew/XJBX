#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;

int g[N][N],d[N];
bool st[N];
int n,m;

int dijkstra(){
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    //最开始节点1没有接入确定最小距离组
    //迭代n次
    for(int i = 0;i < n;i++){
        int t = -1;
        //在确定距离组之外找到距离起点最小的节点
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || d[t] > d[j])){
                t = j;
            }
        }
        // if(t == n) break;
        //利用这个节点更新周围节点
        for(int j = 1;j <= n;j++){
            d[j] = min(d[j],d[t] + g[t][j]);
        }
        //这个节点的最短距离被确认，加入最小距离组
        st[t] = true;
    } 
    
    if(d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main(){
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        //存在重边
        g[x][y] = min(g[x][y],z);
    }
    cout << dijkstra() << endl;
    return 0;
}