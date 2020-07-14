#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> reslut;
        vector<vector<int>> mark;
        vector<string> location;
        for (int i = 0; i < n; i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, reslut, mark);
        return reslut;
    }
private:
    void put_down_the_queen(int x, int y, vector<vector<int>>& mark) {
        static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
        static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++) {
            for (int j = 0; j < 8; j++) {
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
    void generate(int k, int n, vector<string>& location, vector<vector<string>>& reslut, vector<vector<int>>& mark) {
        if (k == n){
            reslut.push_back(location);        
            return;
    }
    for (int i = 0; i < n; i++) {
        if (mark[k][i] == 0) {
            vector<vector<int>> tmp = mark;
            mark[k][i] = 1;
            location[k][i] = 'Q';
            put_down_the_queen(k, i, mark);
            generate(k + 1, n, location, reslut, mark);
            mark = tmp;
            location[k][i] = '.';
        }
    }
}
};