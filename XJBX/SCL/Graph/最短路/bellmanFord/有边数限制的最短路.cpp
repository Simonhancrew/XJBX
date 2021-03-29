#include <iostream>
#include <cstring>
#include <algorithm>

//存在负权回路的话且带负环的回路能和终点联通，最短路是不存在的（最短路趋近于负无穷）
//bellmanford算法看起来比较傻逼，但是可以求有没有负权边
//但是一般用spfa，有些情况下只能用bellmanford算法去处理一些情况

//对于这个算法，我们存所有的边就可以了。
//算法是循环k次（一般会要求走过多少条边，这里设为k），每次遍历所有的边，用上次更新的信息边的距离信息去更新一下当前的距离
//所以我们要准备一个备份数组，这里主要的作用就是防止串联更新


using namespace std;

const int N = 510,M = 1e4 + 10;

struct Edge{
    int a,b,w;
}edge[M];

int n,m,k;
int dist[N],backup[N];

//
int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    
    for(int i = 0;i < k;i++){
        //备份数组，防止串联，每一次都用上次更新的去做更更新。
        //不用本次更新过的点去做更新
        memcpy(backup,dist,sizeof dist);
        for(int j = 0;j < m;j++){
            int a = edge[j].a,b = edge[j].b,w = edge[j].w;
            dist[b] = min(dist[b],backup[a] + w);
        }
    }
    //可能存在负权边，找一个很大的数  
    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge[i].a = a,edge[i].b = b,edge[i].w = w;
    }
    if(bellman_ford() == -1) puts("impossible");
    else cout << dist[n];
    return 0;
}