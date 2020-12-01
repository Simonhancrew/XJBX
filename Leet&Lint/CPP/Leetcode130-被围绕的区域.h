#include<vector>
using namespace std;
//已外边的o为起点，如果不被包围，一定和外围的o相连
//深度优先搜索solution
class Solution{
public:
    int row,col;
    void Dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0||x >= row||y < 0||y >= col||board[x][y] != 'O'){ //最后一个条件可能找到'a'的情况，设置!='o'即可
            return;
        }
        board[x][y] = 'A';
        Dfs(board,x+1,y);
        Dfs(board,x-1,y);
        Dfs(board,x,y+1);
        Dfs(board,x,y-1);
    }
    void solve(vector<vector<char>>& board){
        int n = board.size();
        if(n == 0){
            return;
        }
        for(int i =0;i<row;i++){
            Dfs(board,i,0);
            Dfs(board,i,col-1);
        }
        for(int i = 1;i<col-1;i++){
            Dfs(board,0,i);
            Dfs(board,row-1,i);
        }
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'x';
                }
            }
        }
    }
};
//还可以用并查集去做，就是找到和外围O联通的区域，将这些设为A，剩下的O就全部变为X
//广度优先搜索
#include<queue>

class Solution2{
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return;
        }
        int m = board[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                que.emplace(i, 0);
            }
            if (board[i][m - 1] == 'O') {
                que.emplace(i, m - 1);
            }
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 'O') {
                que.emplace(0, i);   
            }
            if (board[n - 1][i] == 'O') {
                que.emplace(n - 1, i);
            }
        }
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            board[x][y] = 'A';
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
                    continue;
                }
                que.emplace(mx, my);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};