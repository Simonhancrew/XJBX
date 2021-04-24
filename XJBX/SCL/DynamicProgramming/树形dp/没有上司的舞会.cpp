#include <iostream>
#include <cstring>
#include <algorithm>

//树形dp，父子节点不能在一起，所以dp[u][0]表示u位根节点，不选u的最大属性，dp[u][1]是以u位根节点，选择u的时候的最大属性

using namespace std;

const int N = 6010;

int happy[N];
int dp[N][2];
int e[N],ne[N],h[N],idx;
bool has_father[N];

void add(int a,int b){
    has_father[a] = true;
    e[idx] = a,ne[idx] = h[b],h[b] = idx++;
}

//深搜每一个节点状态
void dfs(int u){
    dp[u][1] = happy[u];
    
    for(int i = h[u];i != - 1;i = ne[i]){
        //当前节点的儿子
        int j = e[i];
        //填当前儿子的状态
        dfs(j);
        //更新根节点
        dp[u][1] += dp[j][0];
        dp[u][0] += max(dp[j][1],dp[j][0]); 
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> happy[i];
    
    //图的邻接表
    memset(h,-1,sizeof h);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    
    //找到根节点
    int root = 1;
    while(has_father[root]) root++;
    
    dfs(root);
    
    cout << max(dp[root][0],dp[root][1]) << endl;
    
    return 0;
}