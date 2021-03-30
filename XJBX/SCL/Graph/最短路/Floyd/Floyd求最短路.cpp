#include <iostream>
#include <cstring>
#include <algorithm>

//弗洛伊德的原理和实现都比较简单
//思想应该就是动态规划
//多源最短路问题

using namespace std;

const int N = 210,INF = 1e9;

int n,m,Q;
int d[N][N];

void floyd(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&Q);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while(m--){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        d[a][b] = min(d[a][b],w);
    }
    floyd();
    while(Q--){
        int a,b;
        scanf("%d%d",&a,&b);
        //a->b不存在通路可能比INF小
        if(d[a][b] > INF / 2) puts("impossible");
        else printf("%d\n",d[a][b]);
    }
    return 0;
}