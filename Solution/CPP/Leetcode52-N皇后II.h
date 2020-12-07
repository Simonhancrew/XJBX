#include <vector>
#include <string>
using std::string;
using std::vector;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        res = solveNQueens(n);
        return res.size();
    }
private:
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