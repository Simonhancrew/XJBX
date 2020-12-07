#include <vector>
using namespace std;

class Solution{
public:
    //方向数组
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    void DFS(vector<vector<char>> &board,int x,int y){
        int count = 0;
        for(int i =0;i<8;i++){
            int tx = x+dir_x[i];
            int ty = y + dir_y[i];
            //判断是否越界
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            count += board[tx][ty] == 'M';
        }
        if(count>0){
            board[x][y] = count + '0';
        }else{
            board[x][y] = 'B';
            for(int i = 0;i < 8; i++){
                int tx = x+dir_x[i];
                int ty = y + dir_y[i];
                //递归探索B的8个节点，注意是否越界
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }
                DFS(board,tx,ty);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
        int x =click[0], y = click[1];
        if(board[x][y] == 'M'){
            //到地雷，直接结束
            board[x][y] = 'X';
            return board;
        }else{
            DFS(board,x,y);
        }
        //就挺奇怪的，在这里放DFS(board,x,y);不要else的判断会慢一点
        return board;
    }
};