#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //映射皇后位置和不能再摆放位置
        vector<vector<int>> mark;
        //当前可能的棋盘摆法
        vector<string> location;
        //最后结果
        vector<vector<string>> result;
        //给vector生成一下空间
        for (int i = 0; i < n; i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        //从第一行棋盘开始尝试放置
        generate(0, n, location, result, mark);
        return result;
    }
private:
    void put_down_the_queen(int x, int y, vector<vector<int>>& mark) {
        static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
        static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++) {
            for (int j = 0; j < 8; j++) {
                //所有不能再放的位置设1
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
    void generate(int k, int n, vector<string>& location, vector<vector<string>>& result, vector<vector<int>>& mark) {
        //回溯模板,已经放了n个皇后了
        if (k == n) {
            result.push_back(location);
            return;
        }
        //从上到下，放皇后
        for (int i = 0; i < n; i++) {
            //判断能不能放
            if(mark[k][i] == 0){
                auto tmp = mark;
                mark[k][i] = 1;
                location[k][i] = 'Q';
                put_down_the_queen(k, i, mark);
                generate(k + 1, n, location, result, mark);
                //回溯
                mark = tmp;
                location[k][i] = '.';
            }
        }
    }
};

//leetcode上时间复杂度更好的解法，基于位运算的回溯
class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }
    //因为每次只用考虑下一行能放皇后的位置，所以用位来表示能放置的位置
    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        //回溯模板
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            //columns,diagonals1,diagonals2分别是列和斜边两个方向
            //其值为1的位表示不能放置皇后了
            //(2**n-1)&(~(columns | diagonals1 | diagonals2))就可以得到可以放置皇后的位置
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            //有位置可放,重复放置
            while (availablePositions != 0) {
                //得到最低位1的位置
                int position = availablePositions & (-availablePositions);
                //将最低位1置为0
                availablePositions = availablePositions & (availablePositions - 1);
                //返回position的二进制下末尾的0的个数,可以得到放置皇后的位置
                int column = __builtin_ctz(position);
                queens[row] = column;
                //回溯
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};


//按照行搜索
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n),dg.resize(2 * n),rdg.resize(2 * n);
        board.resize(n,"");
        for(int i = 0;i < n;i++){
            for(int j = 0; j < n;j++){
                board[i].push_back('.');
            }
        }
        dfs(0,n);
        return res;
    }
    void dfs(int u,int n){
        if(u == n){
            res.push_back(board);
            return;
        }
        for(int i = 0;i < n;i++){
            if(!col[i] && !dg[u + i] && !rdg[n - u + i]){
                board[u][i] = 'Q';
                col[i] = dg[i+u] = rdg[n - u + i] = 1;
                dfs(u + 1,n);
                col[i] = dg[i+u] = rdg[n - u + i] = 0;
                board[u][i] = '.';
            }
        }
    }
private:
    vector<int> col,dg,rdg;
    vector<vector<string>> res;
    vector<string> board;
};