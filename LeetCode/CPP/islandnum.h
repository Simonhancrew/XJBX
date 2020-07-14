#pragma once
#include <vector>
using namespace std;
//lt200 µ∫”Ï ˝¡ø
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int is_num = 0;
        vector<vector<int>> mark;
        for (int i = 0; i < grid.size(); i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++) {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (mark[i][j] == 0 && grid[i][j] == '1') {
                    DFS(mark, grid, i, j);
                    is_num++;
                }
            }
        }
        return is_num;
    }
private:
    void DFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
        mark[x][y] = 1;
        static const int dx[] = { -1,1,0,0 };
        static const int dy[] = { 0,0,-1,1 };
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size()) {
                continue;
            }
            if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
                DFS(mark, grid, newx, newy);
            }
        }
    }
};