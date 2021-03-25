#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*

- 数组模拟存储图有两种方法，邻接矩阵和邻接表，一般采用邻接表，这样会省一定的空间。
- 储存无相图的时候要注意构建双边关系，就一个连接要构造两次。
- 树的dfs，会开use数组记录已经访问过的节点，每个节点只会访问一次。
- dfs可以返回当前搜索节点下的节点的数量，只要递归函数的入口记录

*/
const int N = 1e5+10;

//无相图添加双边

int e[2 * N],ne[2 * N],idx;
int h[N];
bool st[N];
int ans = N;
int n;

//树的邻接表实现
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u){
    st[u] = 1;
    int sum = 1,wei = 0;
    for(int i = h[u];i != -1;i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        int s = dfs(j);
        wei = max(s,wei);
        sum += s;
    }
    wei = max(wei, n - sum);
    ans = min(ans,wei);
    //返回节点数
    return sum;
}

int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}