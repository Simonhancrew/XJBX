#include <iostream>

using namespace std;

const int N = 20;
char board[N][N];
int col[N],dg[N],rdg[N];
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0;i < n;i ++) puts(board[i]);
        puts("");
        return;
    }
    for(int i = 0;i < n;i++){
        if(!col[i] && !dg[u + i] && !rdg[n - u + i]){
            board[u][i] = 'Q';
            col[i] = 1;
            dg[u + i] = 1,rdg[n - u + i] = 1;
            dfs(u + 1);
            board[u][i] = '.';
            dg[u + i] = 0,rdg[n - u + i] = 0,col[i] = 0;
        }
    }
}



int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            board[i][j] = '.';
        }
    }
    dfs(0);
   
    return 0;
}