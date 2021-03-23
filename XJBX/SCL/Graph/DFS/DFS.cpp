#include <iostream>

using namespace std;

const int N = 10;
int path[N],st[N];
int n;


void dfs(int u){
    if(u == n){
        for(int i = 0;i < n;i++) cout << path[i] << ' ';
        puts("");
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            st[i] = 1;
            path[u] = i;
            dfs(u + 1);
            st[i] = 0;
            path[u] = 0;
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}