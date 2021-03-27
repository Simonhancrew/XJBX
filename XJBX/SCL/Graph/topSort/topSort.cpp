#include <cstring>
#include <iostream>
using namespace std;

//topsort就是宽搜的一个应用。有向无环图是一定有top序的
//对于每一个入度位0的节点，bfs他的儿子，删除他儿子的一个入度，看看能不嫩入队


const int N = 1e5 + 10;

int n,m;
//h是邻接表，h[i]下面挂着一个链表，h[i]是起始元素
int h[N],e[N],ne[N],idx;
int q[N],d[N];

void add(int a,int b){
    e[idx] =  b,ne[idx] = h[a],h[a] = idx++;
}

bool topsort(){
    int hh = 0,tt = -1;
    
    for(int i = 1;i <= n;i++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    
    while(hh <= tt){
        //top序恰好就是q出队的顺序
        int t = q[hh++];
        for(int i = h[t];i != -1; i = ne[i]){
            int j = e[i];
            //删除入度，看看能不能放队列里
            d[j]--;
            if(d[j] == 0){
                q[++tt] = j;
            } 
        }
    }
    
    return tt == n-1;
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);

    //读入的时候顺便把入度也求了
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
        d[b] ++;
    }
    //topsort先入队所有的0入度节点
    if(topsort()){
        for(int i = 0;i < n;i++) printf("%d ",q[i]);
    }else{
        puts("-1");
    }
    
    return 0;
}