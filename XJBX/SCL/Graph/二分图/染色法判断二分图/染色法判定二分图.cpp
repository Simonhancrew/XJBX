#include <iostream>
#include <cstring>

using namespace std;

// 二分图 当且仅当图中不含奇数环
//只要无奇数环，染色一定可以完成
//遍历所有的点，如果当前点没有被染色，对于这个点去做深搜或者宽搜（如果没有被染色）。
//如果在这个深搜或者宽搜的过程中矛盾了，就返回错误信息


const int N = 1e5 + 10, M = 2e5 + 10;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++; 
}


bool dfs(int u,int c){
    //先给当前点染色
    color[u] = c;
    //遍历周围的点
    for(int i = h[u];i != -1;i = ne[i]){
        int j = e[i];
        //没染色就去染色深搜，过程中有矛盾情况直接判错
        if(!color[j]){
            bool t = dfs(j,3 - c);
            if(!t) return false;
        }else if(color[j] == c){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    //不要忘记初始化表头-1
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(!color[i]){
            //过程中矛盾了就不存在二分图
            bool t = dfs(i,1);
            if(!t){
                flag = false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");

    return 0;
}