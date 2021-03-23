#include <iostream>
//更类似于原始的搜索，一个个格子的搜索
using namespace std;

const int N = 20;
char board[N][N];
int row[N],col[N],dg[N],rdg[N];
int n;

//行，列，皇后放下的数量
void dfs(int x,int y,int s){
    if(y == n) x++,y = 0;
    if(x == n){
        if(s == n){
            for(int i = 0;i < n;i++) puts(board[i]);
            puts("");
        }
        return;
    }
    
    //不妨皇后
    dfs(x,y+1,s);

    //放皇后且可以放
    if(!row[x] && !col[y]  && !dg[x + y] && !rdg[n -y + x]){
        board[x][y] = 'Q',row[x] = 1,col[y] = 1;
        dg[x + y] = 1,rdg[n - y + x] = 1;
        dfs(x,y+1,s+1);
        row[x] = col[y] = dg[x + y] = rdg[n - y + x] = 0;
        board[x][y] = '.';
    }
}



int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            board[i][j] = '.';
        }
    }
    dfs(0,0,0);
   
    return 0;
}