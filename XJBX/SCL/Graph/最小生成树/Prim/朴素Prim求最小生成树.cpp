#include <cstring>
#include <iostream>
#include <algorithm>

//pirm算法和dijsktra算法很像，都是首先初始距离无穷大
//之后去做n次更新，每次找到不在集合中的距离集合的最近的点
//然后把他加入集合，更新生成权值，此时如果他离集合的距离是无穷大的话就代表树不连通
//最后更新其周围的点到集合的距离（dijsktra是到起点）

using namespace std;


const int N = 520,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int d[N];
bool st[N];


int prim(){
    int res = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || d[t] > d[j])){
                t = j;
            }
        }
        if(i && d[t] == INF) return INF;
        
        //考虑负环的情况，需要先更新距离再去更新d 
        if(i) res += d[t];

        //此时再更新周围影响的边已经在集合中，不会堆后续影响
        for(int j = 1;j <= n;j++) d[j] = min(d[j],g[t][j]);
        
        st[t] = true;
    }
    return res;
}


int main(){
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    memset(d,0x3f,sizeof d);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int t = prim();
    if(t == INF) puts("impossible");
    else cout << t;
    return 0;
}
